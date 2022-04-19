#define EPSILON 1e-10
#define BIG_EPSILON_STEP 5e-2
#define BIG_EPSILON_COMPARE 1e-3

const int MAX_ITERATIONS = 500;//Maximum number of iterations
const int MAX_DEF_ROOTS = 10;//Maximum number of roots (arbitrary)
const double RANGE = 10000.0;

void Failure()
{
  // still need to finish this
}

double* NewtonsMethodPolynomial(const Polynomial& poly, double approx_root)
{
  double* prev_guess = approx_root;
  double guess = approx_root;
  int iterations = 0;

  Polynomial derivative = poly.Derivative();
  //cout<<poly.Evaluate(guess);
  while(fabs(poly.Evaluate(guess)) > EPSILON)
  {
    iterations++;
    if(iterations == MAX_ITERATIONS + 1)
      Failure();
    prev_guess = guess;
    guess = prev_guess - poly.Evaluate(prev_guess) /
	    derivative.Evaluate(prev_guess);
  }
  //  Root is found
  return guess;
}

double* GetRoots(const Polynomial& poly, int& num_roots)
{
  double* roots = new double[MAX_DEF_ROOTS];
  for(int i = 0;i < MAX_DEF_ROOTS; i++)
    roots[i] = 0.0;
  num_roots = 0;

  for(double approx = -RANGE; approx < +RANGE;
    approx += BIG_EPSILON_STEP)
  {
    if(fabs(poly.Evaluate(approx)) < BIG_EPSILON_COMPARE)
    {
      double result = NewtonsMethodPolynomial(poly, approx);
      if(fabs(poly.Evaluate(result)) < EPSILON) // root found
      {
	int unique = 1;
	//  make sure that only unique results are added
	for(int r = 0; r < num_roots; r++)
	  if(fabs(result - roots[r]) < EPSILON) // duplicate root
	  {
	    unique = 0;
	    break;
	  }
	if(unique)
	  roots[num_roots++] = result;
      }
    }
  }
  return roots;
}
