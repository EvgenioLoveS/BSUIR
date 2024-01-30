#include <iostream> 
long long reshenie(long long k)
{
	int m;
	if (fabs(sin(k) <= 0.2))
	{
		m = k;
	}
	else if (fabs(sin(k) < 0.9 && fabs(sin(k)) >= 0.2))
	{
		m = sqrt(k);
	}
	else if (fabs(sin(k) >= 0.9))
	{
		m = sqrt(sqrt(k));
	}
	return m;
}