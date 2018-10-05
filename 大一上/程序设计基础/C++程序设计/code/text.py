import math
def quadratic(a,b,c):
	x1=(-b+math.sqrt(b*b-4*a*c))/(2*a)
	x2=(-b-math.sqrt(b*b-4*a*c))/(2*a)
	return x1,x2
print(quadratic(2,3,1))
print(quadratic(1,3,-4))
print(quadratic(2,7,3))
def power(x,n=2):
	sum=1
	while n>0:
		sum = sum*x
		n = n - 1
	return sum
print(power(3))