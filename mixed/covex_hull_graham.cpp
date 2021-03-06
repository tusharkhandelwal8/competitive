#include <bits/stdc++.h>
typedef long long ll;
#define INF 10000000001
using namespace std; 
struct Point 
{ 
    ll x, y; 
}; 
  

Point p0; 
  

Point nextToTop(stack<Point> &S) 
{ 
    Point p = S.top(); 
    S.pop(); 
    Point res = S.top(); 
    S.push(p); 
    return res; 
} 
  

void swap(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  

ll distSq(Point p1, Point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 
  

int orientation(Point p, Point q, Point r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
} 
  
int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   
   int o = orientation(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 
bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
		return true; 
	return false; 
} 


bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

 
	if (o1 != o2 && o3 != o4) 
		return true; 

	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false; 
} 

bool isInside(vector<Point> polygon, ll n, Point p) 
{ 
	
	if (n < 3) return false; 

	
	Point extreme = {INF, p.y+1}; 

	int count = 0, i = 0; 
	do
	{ 
		int next = (i+1)%n; 

		
		if (doIntersect(polygon[i], polygon[next], p, extreme)) 
		{ 
			
			if (orientation(polygon[i], p, polygon[next]) == 0) 
			   {
			    return false;}

			count++; 
		} 
		i = next; 
	} while (i != 0); 

	 
	return count&1; 
} 
  

void convexHull(vector<Point> allp, int n,vector<vector<Point>> &fq) 
{  
    vector<Point> mnh,polygons;
   vector<Point> nh;
    
   int ymin = allp[0].y, min = 0; 
   for (int i = 1; i < n; i++) 
   { 
     int y = allp[i].y; 
  
     
     if ((y < ymin) || (ymin == y && 
         allp[i].x < allp[min].x)) 
        ymin = allp[i].y, min = i; 
   } 
  
    
   swap(allp[0], allp[min]); 
  

   p0 = allp[0]; 
   qsort(&allp[1], n-1, sizeof(Point), compare); 
  
   
   int m = 1; 
   for (int i=1; i<n; i++) 
   { 
       while (i < n-1 && orientation(p0, allp[i], allp[i+1]) == 0) 
          { mnh.push_back(allp[i]);
              i++;
          }
  
  
       allp[m] = allp[i]; 
       m++;   
   } 
   if(m<3)
    return ;
  
   
  
  
    
   stack<Point> S; 
   S.push(allp[0]); 
   S.push(allp[1]); 
   S.push(allp[2]); 
  
   
   for (int i = 3; i < m; i++) 
   { 
      
      while (orientation(nextToTop(S), S.top(), allp[i]) != 2) 
         {
             mnh.push_back(S.top());
             S.pop();
         }
      S.push(allp[i]); 
   } 
   vector<Point> cp;
   while(!S.empty())
   {
       polygons.push_back(S.top());
       cp.push_back(S.top());
      
       S.pop();
   }
   
   fq.push_back(polygons);
  
   for(int k=0;k<mnh.size();k++)
   {  if(isInside(cp , cp.size(), mnh[k]))
       nh.push_back(mnh[k]);
   }
    if(nh.size()>=3)
        convexHull(nh, nh.size(),fq);
     return ;
        
        
} 
  


int main() 
{  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
   while(t--)
   {
       int n,q;
        cin >> n >> q;
       vector<Point> inp;
       for(int i=0;i<n;i++)
       {    Point points;
            cin >> points.x  >> points.y;
         inp.push_back(points);
       }
    
	vector<vector<Point>> fq;
	if(inp.size()>=3)
	  convexHull(inp, n,fq); 
    
     
	while(q--)
	{
	    long long int xi,yi;
	     cin >> xi >> yi;
	    int count=0;
	    Point qi;
	    qi.x=xi;
	    qi.y=yi;
	   
	    for(int yes=0;yes<fq.size();yes++)
	   {   
	        
	        if(isInside( fq[yes], fq[yes].size(), qi))
	            count++;
	         else
	            break;
	           
	             
	   } 
	   cout << count << "\n";
	}
	
   }

	 
	 
	return 0; 
} 
