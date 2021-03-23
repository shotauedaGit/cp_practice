#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define MOD 1000000007
#define MOD2 998244353

template<class T,class U>bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U>bool chmin(T &a, const U &b){if(b<a){a=b;return 1;}return 0;}

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rep1(i,a,b) for(int a_=(a),b_=(b),i=a_;i<b_;++i)
#define repr(i,n) for(int _i=(n),i=_i;i>0;--i)

#define db(x) cerr<<#x<<" = "<<x<<" ";
#define db2(x,y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<") ";
#define db3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<") ";
#define ln cout<<endl;

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;
typedef long double ld;

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

float cross(float ax,float ay,float bx,float by,float x,float y){
    float px = bx - ax;
    float py = by - ay;

    return x*py - y*px;
}

struct POINT2{  //      二次元座標
        float x,y;
};

//      三角形の頂点座標を定義
POINT2 tp[]={
        { -1.0,       0.0 },
        { 1.0,      0.0 },
        { 1.0,      2.0 }};

//      調べたい点の座標

POINT2 o={ 2384.52,     1708.61 };

//      ベクトルクラス
class VEC2{
        float x,y;
public:
        void set(float a,float b){
                x=a;
                y=b;
        }
        double cross(VEC2& b){      //      外積の計算
                double r;
                r= x * b.y - y * b.x;
                return r;
        }
};

//      三角形クラス
struct TRIANGLE{        //      三角形
        POINT2* p;      //      三角形の座標
        void set(POINT2* ap){   //      座標の設定
                p=ap;
        }
        void put(void){
                printf("%g,%g,%g,%g,%g,%g\n",p[0].x, p[0].y ,p[1].x, p[1].y,p[2].x, p[2].y);
        }
        int hit(POINT2& o){        // 三角形内に座標oが含むか調べる
                VEC2 vec[6];
                double f[3];            
                vec[1].set( p[0].x - p[2].x , p[0].y - p[2].y );
                vec[3].set( o.x - p[2].x , o.y - p[2].y );
                f[0]=vec[1].cross(vec[3]);

                vec[2].set( p[1].x - p[0].x , p[1].y - p[0].y );
                vec[4].set( o.x - p[1].x , o.y - p[1].y );
                f[1]=vec[2].cross(vec[4]);

                vec[0].set( p[2].x - p[1].x , p[2].y - p[1].y );
                vec[5].set( o.x - p[1].x , o.y - p[1].y );
                f[2]=vec[0].cross(vec[5]);

                
                if(f[0]<0 && f[1]<0 && f[2]<0)
                        return 1;
                if(f[0]>0 && f[1]>0 && f[2]>0)
                        return 1;

                if(f[0]==0 && f[1]==0 && f[2]==0)return 0;

                return -1;
        }
};



struct Point {
	float x = 0.0f, y = 0.0f;

	Point() { x = 0.0f; y = 0.0f; }
	Point(float _x, float _y) :x(_x), y(_y) {}
	

	bool operator==(Point p) {
		return (x == p.x) && (y == p.y);
	}

	Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }
	Point operator*(double k) { return Point(k * x, k * y); }
	Point operator/(double k) { return Point(x / k, y / k); }


	float Dist(Point tg) {
		float dx = fabsf(x - tg.x);
		float dy = fabsf(y - tg.y);
		return sqrtf(dx * dx + dy * dy);
	}

	float Cross_z(Point tg) {//クロス関のz成分.平面上の座標なのでこれしかいらない.
		return x * tg.y - y * tg.x;
	}

	float dot(Point p) {
		return x * p.x + y * p.y;
	}

	void DBG(string name) {
		cout << fixed << setprecision(3) <<name<<"("<< x << "," << y <<")"<< endl;
	}
};

struct Edge {// v0 ---> v1
	Edge() {}
	Edge(Point _v0, Point _v1) :v0(_v0), v1(_v1) {}
	bool operator==(Edge e) {
		return (v0 == e.v0) && (v1 == e.v1) || (v0 == e.v1) && (v1 == e.v0);//逆順も考慮しておく
	}
	Point v0, v1;

	void DBG(string name) {
		cout << name << endl;
		v0.DBG("v0");v1.DBG("v1");
	}
};

struct Circle {
	Circle() {}
	Circle(Point c, float _r) :center(c), r(_r) {}
	
	bool operator==(Circle c) {
		return (center == c.center) && (r == c.r);
	}
	Point center;
	float r = 0.0;
};

struct Triangle {
	Point A, B, C;
	Edge AB, BC, CA;
	Circle Outer;
	float S = 0.0f;

	bool exist = true;

	Triangle() {}
	Triangle(Point _a,Point _b,Point _c):A(_a), B(_b), C(_c){
		/*
		AB.v0 = A; AB.v1 = B;
		BC.v0 = B; BC.v1 = C;
		CA.v0 = C; CA.v1 = A;
		*/

		AB = Edge(A, B);
		BC = Edge(B, C);
		CA = Edge(C, A);

		Outer = getOuterCentroid();
		S = calcArea();
	}

	//Triangle getTriangleShareEdge(Edge e);//全探索...

	float calcArea();

	Circle getOuterCentroid();//外心を返す
	Edge OppositeEdge(Point p);//反対の辺を返す
	Point OppositePonit(Edge e);//反対の頂点を返す
	bool isIncluded(Point p);//この頂点は内包されているか？？
	bool isIncluded(Edge e);//この辺を含んでいるか？？
	bool isPointShared(Triangle t);//この頂点を含んでいるか？？
	bool isEdgeShared(Triangle T);

	bool operator==(Triangle &t);
	void del();//delete this triangles


	void DBG(string name) {
		cout << name << endl;
		A.DBG("A"); B.DBG("B"); C.DBG("C");
		Outer.center.DBG("O");
		if (exist)cout << "exist" << endl;
		else cout << "deleted" << endl;
	}

};


float Triangle::calcArea() {
	Point P = C - A;
	Point Q = B - A;
	return (fabsf(P.x * Q.y - P.y * Q.x)) / 2.0f;
}


void Triangle::del() {
	exist = false;
}

Circle Triangle::getOuterCentroid() {
	float tmp = 2.0 * ((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x));
	float cx = ((C.y - A.y) * (B.x * B.x - A.x * A.x + B.y * B.y - A.y * A.y) + (A.y - B.y) * (C.x * C.x - A.x * A.x + C.y * C.y - A.y * A.y)) / tmp;
	float cy = ((A.x - C.x) * (B.x * B.x - A.x * A.x + B.y * B.y - A.y * A.y) + (B.x - A.x) * (C.x * C.x - A.x * A.x + C.y * C.y - A.y * A.y)) / tmp;

	Point cent(cx, cy);
	float cr = cent.Dist(A);
	Circle ret(cent, cr);
	return ret;
}

Edge Triangle::OppositeEdge(Point p) {
	if (p == A)return BC;
	if (p == B)return CA;
	if (p == C)return AB;

	//return;//例外
}

Point Triangle::OppositePonit(Edge e) {
	if (e == AB)return C;
	if (e == BC)return A;
	if (e == CA)return B;

	//return;//例外
}

bool Triangle::isIncluded(Point P) {
	Point vAB = Point(A.x - C.x, A.y - C.y);
	Point vBC = Point(B.x - A.x, B.y - A.y);
	Point vCA = Point(C.x - A.x, C.y - A.y);

	float ABxP = (B-A).Cross_z(P);//外積のz成分を持ってくる
	float BCxP = (C-B).Cross_z(P);
	float CAxP = (A-C).Cross_z(P);

	if ((ABxP > 0 && BCxP > 0 && CAxP > 0) || (ABxP < 0 && BCxP < 0 && CAxP < 0)) {//全部同じ方向ならOK
		return true;
	}
	else {
		return false;
	}
}

bool Triangle::isPointShared(Triangle t) {
	return  (t.A == A || t.A == B || t.A == C) ||
		(t.B == A || t.B == B || t.B == C) ||
		(t.C == A || t.C == B || t.C == C);
}

bool Triangle::operator==(Triangle& t) {
	return (AB == t.AB || AB == t.BC || AB == t.CA) && (BC == t.AB || BC == t.BC || BC == t.CA);
}


bool Triangle::isIncluded(Edge e) {
	return (AB == e) || (BC == e) || (CA == e);
}

bool Triangle::isEdgeShared(Triangle T) {
	return isIncluded(T.AB) || isIncluded(T.BC) || isIncluded(T.CA);
}

int main(){
        Point A(-1.0,0.0);
        Point B(1.0,0.0);
        Point C(1.0,2.0);
        Triangle t(A,B,C);

        while(1){
            float x,y;
            cin>>x>>y;
            if(x == 1.14&&y==5.14)break;
            Point P(x,y);

            /*
            if(t.hit(o)==1){
                    printf("hit !!\n");  //      三角形に点が含まれる
            }else if(t.hit(o)==-1){
                    printf("non hit !!\n");      //      三角形に点が含まれない
            }else{
                printf("zero !!\n");
            }*/

            if(t.isIncluded(P)){
                    printf("hit !!\n");  //      三角形に点が含まれる
            }else{
                    printf("non hit !!\n");      //      三角形に点が含まれない
            }
        }

}