import sys
a=0
b=0
c=0
d=0
for _ in range(4):
	A = input()
	if A=="H":
		a+=1
	elif A == "2B":
		b+=1
	elif A=="3B":
		c+=1
	elif A=="HR":
		d+=1
if a==b==c==d==1:
  print("Yes")
else:
	print("No")