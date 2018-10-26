#include<iostream>
#include<string.h>
using namespace std;
int c[100][100];
int b[100][100];
void LCSLength(int m,int n,string x,string y,int (&c)[100][100],int (&b)[100][100]){
	int i,j;
	for(i = 1;i <= m; i++)
		c[i][0] = 0;
	for(i = 1;i <= n; i++)
		c[0][i] = 0;
	for(i = 1;i <= m; i++)
		for(j = 1;j <= n; j++){
			if(x[i] == y[j]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}
}
void LCS(int i,int j,string z,int (&b)[100][100]){
	if(i == 0 || j == 0)
		return;
	if(b[i][j] == 1){
		LCS(i-1,j-1,z,b);
		cout<<z[i];
	}
	else if(b[i][j] == 2)
		LCS(i-1,j,z,b);
	else
		LCS(i,j-1,z,b);
}
int main(){
	int length1,length2;
	string s1,s2,s3;
	cin>>s1>>s2;
	length1 = s1.length();
	length2 = s2.length(); 
	LCSLength(length1,length2,' '+s1,' '+s2,c,b);
	LCS(length1,length2,' '+s1,b);
	cout<<endl<<c[length1][length2]<<endl;
return 0;
} 
