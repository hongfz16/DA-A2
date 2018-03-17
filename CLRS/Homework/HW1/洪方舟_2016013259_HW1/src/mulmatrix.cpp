#include <iostream>
#include <ctime>
using namespace std;

#define MAXN 1000

int** createSp(int n,int m)
{
	int **a=new int* [n];
	for(int i=0;i<n;++i)
	{
		a[i]=new int[m];
		for(int j=0;j<m;++j)
			a[i][j]=0;
	}
	return a;
}

int** createMa(int n, int m)
{
	int **a = new int* [n];
	for(int i=0;i<n;++i)
	{
		a[i]=new int[m];
		for(int j=0;j<m;++j)
		{
			a[i][j]=rand()%MAXN;
		}
	}
	return a; 
}

void desMa(int** a,int n,int m)
{
	for(int i=0;i<n;++i)
	{
		delete []a[i];
	}
	delete []a;
}

int** AddMatrix(int** a,int** b,int n,int m)
{
	if(a==nullptr || b==nullptr)
		return nullptr;
	int** c=createSp(n,m);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	return c;
}

int** MiMatrix(int** a,int** b,int n,int m)
{
	if(a==nullptr || b==nullptr)
		return nullptr;
	int** c=createSp(n,m);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
	return c;
}

bool IsEqualMatrix(int** a,int** b,int n,int m)
{
	if(a==nullptr || b==nullptr)
		return false;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j]!=b[i][j])
				return false;
		}
	}
	return true;
}

int** SubMatrix(int** a,pair<int,int> x,pair<int,int> y)
{
	if(a==nullptr)
		return nullptr;
	int lx=x.second-x.first;
	int ly=y.second-y.first;
	int** c=createSp(lx,ly);
	for(int i=x.first;i<x.second;++i)
	{
		for(int j=y.first;j<y.second;++j)
		{
			c[i-x.first][j-y.first]=a[i][j];
		}
	}
	return c;
}

int** SimpleMulMatrix(int** a,int an,int am,int** b,int bn,int bm)
{
	if(am!=bn)
		return nullptr;
	if(a==nullptr || b==nullptr)
		return nullptr;
	int** c=createSp(an,bm);
	for(int i=0;i<an;++i)
	{
		for(int j=0;j<bm;++j)
		{
			for(int k=0;k<am;++k)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
	return c;
}

int** Strassen(int** a,int an,int am,int** b,int bn,int bm)
{
	if(am!=bn)
		return nullptr;
	if(a==nullptr || b==nullptr)
		return nullptr;
	int th=1;
	if(an<=th || am<=th || bm<=th)
	{
		return SimpleMulMatrix(a,an,am,b,bn,bm);
	}
	int midan=an/2;
	int midam=am/2;
	int midbn=bn/2;
	int midbm=bm/2;
	int mid=midan;

	int** a11=SubMatrix(a,pair<int,int>(0,midan),pair<int,int>(0,midam));
	int** a12=SubMatrix(a,pair<int,int>(0,midan),pair<int,int>(midam,am));
	int** a21=SubMatrix(a,pair<int,int>(midan,an),pair<int,int>(0,midam));
	int** a22=SubMatrix(a,pair<int,int>(midan,an),pair<int,int>(midam,am));
	int** b11=SubMatrix(b,pair<int,int>(0,midbn),pair<int,int>(0,midbm));
	int** b12=SubMatrix(b,pair<int,int>(0,midbn),pair<int,int>(midbm,bm));
	int** b21=SubMatrix(b,pair<int,int>(midbn,bn),pair<int,int>(0,midbm));
	int** b22=SubMatrix(b,pair<int,int>(midbn,bn),pair<int,int>(midbm,bm));

	int** s1=MiMatrix(b12,b22,midbn,bm-midbm);
	int** s2=AddMatrix(a11,a12,midan,midam);
	int** s3=AddMatrix(a21,a22,an-midan,midam);
	int** s4=MiMatrix(b21,b11,midbn,midbm);
	int** s5=AddMatrix(a11,a22,midan,midam);
	int** s6=AddMatrix(b11,b22,midbn,midbm);
	int** s7=MiMatrix(a12,a22,midan,am-midam);
	int** s8=AddMatrix(b21,b22,bn-midbn,midbm);
	int** s9=MiMatrix(a11,a21,midan,midam);
	int** s10=AddMatrix(b11,b12,midbn,midbm);

	int** p1=Strassen(a11,mid,mid,s1,mid,mid);
	int** p2=Strassen(s2,mid,mid,b22,mid,mid);
	int** p3=Strassen(s3,mid,mid,b11,mid,mid);
	int** p4=Strassen(a22,mid,mid,s4,mid,mid);
	int** p5=Strassen(s5,mid,mid,s6,mid,mid);
	int** p6=Strassen(s7,mid,mid,s8,mid,mid);
	int** p7=Strassen(s9,mid,mid,s10,mid,mid);

	int** c11=AddMatrix(MiMatrix(AddMatrix(p5,p4,mid,mid),p2,mid,mid),p6,mid,mid);
	int** c12=AddMatrix(p1,p2,mid,mid);
	int** c21=AddMatrix(p3,p4,mid,mid);
	int** c22=MiMatrix(MiMatrix(AddMatrix(p5,p1,mid,mid),p3,mid,mid),p7,mid,mid);

	int** c=createSp(an,bm);
	for(int i=0;i<mid;i++)
	{
		for(int j=0;j<mid;++j)
		{
			c[i][j]=c11[i][j];
		}
	}
	for(int i=mid;i<an;i++)
	{
		for(int j=0;j<mid;++j)
		{
			c[i][j]=c21[i-mid][j];
		}
	}
	for(int i=0;i<mid;i++)
	{
		for(int j=mid;j<bm;++j)
		{
			c[i][j]=c12[i][j-mid];
		}
	}
	for(int i=mid;i<an;i++)
	{
		for(int j=mid;j<bm;++j)
		{
			c[i][j]=c22[i-mid][j-mid];
		}
	}

	int n=mid;


	desMa(a11,n,n);
	desMa(a12,n,n);
	desMa(a21,n,n);
	desMa(a22,n,n);
	desMa(b11,n,n);
	desMa(b12,n,n);
	desMa(b21,n,n);
	desMa(b22,n,n);

	desMa(s1,n,n);
	desMa(s2,n,n);
	desMa(s3,n,n);
	desMa(s4,n,n);
	desMa(s5,n,n);
	desMa(s6,n,n);
	desMa(s7,n,n);
	desMa(s8,n,n);
	desMa(s9,n,n);
	desMa(s10,n,n);

	desMa(p1,n,n);
	desMa(p2,n,n);
	desMa(p3,n,n);
	desMa(p4,n,n);
	desMa(p5,n,n);
	desMa(p6,n,n);
	desMa(p7,n,n);

	desMa(c11,n,n);
	desMa(c12,n,n);
	desMa(c21,n,n);
	desMa(c22,n,n);

	return c;
}

void printMatrix(int** a,int n ,int m)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void test(int n)
{
	int** a=createMa(n,n);
	int** b=createMa(n,n);

	//printMatrix(a,n,n);
	//printMatrix(b,n,n);

	clock_t start_c=clock();
	int** c=SimpleMulMatrix(a,n,n,b,n,n);
	clock_t end_c=clock();
	cout<<"SimpleMulMatrix"<<endl;
	cout<<(end_c-start_c)/1000.0<<"ms"<<endl;
	cout<<(end_c-start_c)/1000000.0<<"s"<<endl;
	//printMatrix(c,n,n);
	start_c=clock();
	int** cc=Strassen(a,n,n,b,n,n);
	end_c=clock();
	cout<<"Strassen"<<endl;
	cout<<(end_c-start_c)/1000.0<<"ms"<<endl;
	cout<<(end_c-start_c)/1000000.0<<"s"<<endl;
	//printMatrix(cc,n,n);

	if(IsEqualMatrix(c,cc,n,n))
		cout<<"Correct!"<<endl;
	else
		cout<<"Wrong!"<<endl;

	desMa(a,n,n);
	desMa(b,n,n);
	desMa(c,n,n);
	desMa(cc,n,n);
}

int main()
{
	srand((unsigned)time(NULL));
	int n=1;
	
	for(int i=0;i<12;++i)
	{
		cout<<"----------------"<<endl;
		cout<<"Size of the matrix: "<<n*2<<endl;
		test(n*=2);
		cout<<"----------------"<<endl;
	}
	return 0;
}