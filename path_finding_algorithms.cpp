#include<bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

struct method
{
	bool operator()(pair<pair<int,int>,double>&p1,pair<pair<int,int>,double>&p2)
	{
		if(p1.second > p2.second)
			return true;
		return false;
	}
};

class node
{
    public:
        bool right,down;//path maker
        char ch;//obstacle or not
        bool vis;//visited or not
        pair<int,int>prev;//previous element
        
        node()
        {
            ch='.';
            vis=false;
            right=false;
            down=false;
            prev={-1,-1};
        }
};

class matrix
{
    public:
        int m,n;//rows,columns
        node **boa;//matrix of nodes
        pair<int,int>start,end;//starting node,ending node
        
        matrix(int M,int N)
        {
            m=M;
            n=N;
            boa=new node*[m];
            for(int i=0;i<m;i++)
               boa[i]=new node[n];
        }
        
        void print()//printing the matrix
        {
            int i,j;
            for(i=0;i<m;i++)
            {
				cout<<'\t';
				cout<<'\t';
                for(j=0;j<n;j++)
                {
					if(boa[i][j].ch == 'X')
						cout << BOLDCYAN << "X" << RESET;
					else if(boa[i][j].vis)
						cout<< RED<< boa[i][j].ch << RESET;
					else
						cout<< boa[i][j].ch;
                }
                cout<<'\n';    
            }
        }
        
        void BFS()//finding the path
        {
            using namespace std::this_thread;     // sleep_for, sleep_until
            using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
            using std::chrono::system_clock;
            int i,x,y,j,cnt;
            pair<int,int>p;
            queue<pair<int,int>> q;
            q.push(start);
            boa[start.first][start.second].vis=true;
            while(!q.empty())
            {
                p=q.front();
                q.pop();
                if(p==end)
                    break;
                x=p.first;
                y=p.second;
                if(x!=m-1 && boa[x+1][y].vis==false && boa[x+1][y].ch!='X')
                {
                    boa[x+1][y].vis=true;//visited
                    boa[x+1][y].prev={x,y};//update previous 
                    q.push({x+1,y});//push to the queue
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tBREADTH FIRST SEARCH ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
					if(x+1 == end.first && y == end.second)
						break;
				
                }
                if(x!=0 && boa[x-1][y].vis==false && boa[x-1][y].ch!='X')
                {
                    boa[x-1][y].vis=true;
                    boa[x-1][y].prev={x,y};
                    q.push({x-1,y});
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tBREADTH FIRST SEARCH ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
					if(x-1 == end.first && y == end.second)
						break;
                }
                if(y!=n-1 && boa[x][y+1].vis==false && boa[x][y+1].ch!='X')
                {
                    boa[x][y+1].vis=true;
                    boa[x][y+1].prev={x,y};
                    q.push({x,y+1});
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tBREADTH FIRST SEARCH ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
					if(x == end.first && y+1 == end.second)
						break;
                }
                if(y!=0 && boa[x][y-1].vis==false && boa[x][y-1].ch!='X')
                {
                    boa[x][y-1].vis=true;
                    boa[x][y-1].prev={x,y};
                    q.push({x,y-1});
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tBREADTH FIRST SEARCH ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
					if(x == end.first && y-1 == end.second)
						break;
                }
            }
            if(boa[end.first][end.second].vis==false)//No path exist
            {
                cout<<"\t\tThere's no path that connects starting point to destination!!!"<<'\n';
                return ;
            }
            else
            {
				for(i=0,cnt=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						if(boa[i][j].vis)
							cnt++;
					}
				}
				cout<<'\n';
				cout<<"\t\tNumber of visited cells = "<<cnt<<'\n';
				sleep_until(system_clock::now() + 3000ms); //delay
			}
        }
        
        double dist(int x,int y)
        {
			return sqrt((end.first - x)*(end.first - x) + (end.second -y)*(end.second -y));
		}
        
        void astar()
        {
			using namespace std::this_thread;     // sleep_for, sleep_until
            using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
            using std::chrono::system_clock;
            int i,x,y,j,cnt;
            double d;
            pair<pair<int,int>,double>p;
            priority_queue<pair<pair<int,int>,double>,vector<pair<pair<int,int>,double>>,method> pq;
            d=dist(start.first,start.second);
            pq.push({start,d});
            boa[start.first][start.second].vis=true;
            while(!pq.empty() && pq.top().second > 0)
            {
				p=pq.top();
                pq.pop();
                x=p.first.first;
                y=p.first.second;
                if(x!=m-1 && boa[x+1][y].vis==false && boa[x+1][y].ch!='X')
                {
                    boa[x+1][y].vis=true;//visited
                    boa[x+1][y].prev={x,y};//update previous 
                    d=dist(x+1,y);
                    pq.push({{x+1,y},d});//push to the queue
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tA-STAR ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting				
                }
                if(x!=0 && boa[x-1][y].vis==false && boa[x-1][y].ch!='X')
                {
                    boa[x-1][y].vis=true;
                    boa[x-1][y].prev={x,y};
                    d=dist(x-1,y);
                    pq.push({{x-1,y},d});
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tA-STAR ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
                }
                if(y!=n-1 && boa[x][y+1].vis==false && boa[x][y+1].ch!='X')
                {
                    boa[x][y+1].vis=true;
                    boa[x][y+1].prev={x,y};
                    d=dist(x,y+1);
                    pq.push({{x,y+1},d});
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tA-STAR ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
                }
                if(y!=0 && boa[x][y-1].vis==false && boa[x][y-1].ch!='X')
                {
                    boa[x][y-1].vis=true;
                    boa[x][y-1].prev={x,y};
                    d=dist(x,y-1);
                    pq.push({{x,y-1},d});
                    sleep_until(system_clock::now() + 100ms); //delay
					system("clear");//clearing the screen
					cout<<"\n\n";
					cout<<"\t\tA-STAR ALGORITHM"<<'\n';
					cout<<'\n';
					cout<<'\n';
					print();    //reprinting
                }
			}
			if(pq.empty())
			{
				cout<<"\t\tThere's no path that connects starting point to destination!!!"<<'\n';
                return ;
			}
			else
            {
				for(i=0,cnt=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						if(boa[i][j].vis)
							cnt++;
					}
				}
				cout<<'\n';
				cout<<"\t\tNumber of visited cells = "<<cnt<<'\n';
				sleep_until(system_clock::now() + 3000ms); //delay
			}
		}
};

int main()
{
    int m,n,i,x,y,z;
    system("clear");
    cout<<"Enter the rows and columns of matrix"<<'\n';
    cin>>m>>n;//rows,columns
    matrix b(m,n),bb(m,n);
    cout<<"Enter the starting coordinates"<<'\n';
    cin>>x>>y;
    while(x<0 || x>m-1 || y<0 || y>n-1)//while invalid coordinate
    {
        cout<<"Enter a valid coordinate!!!"<<'\n';
        cout<<"x-coordinate should lie between 0 to "<<m-1<<'\n';
        cout<<"y-coordinate should lie between 0 to "<<n-1<<'\n';
        cin>>x>>y;
    }
    b.boa[x][y].ch='S';
    b.start={x,y};
    bb.boa[x][y].ch='S';
    bb.start={x,y};
    //boa[x][y].vis=true;
    cout<<"Enter the destination coordinates"<<'\n';
    cin>>x>>y;
    while(x<0 || x>m-1 || y<0 || y>n-1)//while invalid coordinate
    {
        cout<<"Enter a valid coordinate!!!"<<'\n';
        cout<<"x-coordinate should lie between 0 to "<<m-1<<'\n';
        cout<<"y-coordinate should lie between 0 to "<<n-1<<'\n';
        cin>>x>>y;
    }
    b.boa[x][y].ch='D';
    b.end={x,y};
    bb.boa[x][y].ch='D';
    bb.end={x,y};
    cout<<"Enter the number of obstacles"<<'\n';
    cin>>z;
    while(z>n*m-2)//while obstacles greater than size of matrix
    {
        cout<<"Number of obstacle must be less than or equal to"<<n*m-2<<'\n';
        cin>>z;
    }
    for(i=0;i<z;i++)
    {
        system("clear");
        b.print();
        cout<<"Enter the coordinate of the obstacle "<<i+1<<'\n';
        cin>>x>>y;
        while(x<0 || x>m-1 || y<0 || y>n-1 || (b.boa[x][y].ch != '.'))//while invalid coordinate
        {
            if(x<0 || x>m-1 || y<0 || y>n-1)//out of bound
            {
                cout<<"Enter a valid coordinate!!!"<<'\n';
                cout<<"x-coordinate should lie between 0 to "<<m-1<<'\n';
                cout<<"y-coordinate should lie between 0 to "<<n-1<<'\n';
            }
            else if(b.boa[x][y].ch=='S')//starting coordinate
                cout<<"Starting point cannot be an obstacle"<<'\n';
            else if(b.boa[x][y].ch=='D')//destination coordinate
                cout<<"Destination point cannot be an obstacle"<<'\n';
            else
                cout<<"You have already entered this coordinate!!"<<'\n';
            cin>>x>>y;
        }
        b.boa[x][y].ch='X';
        bb.boa[x][y].ch='X';
    }
    b.BFS();//finding the path
    bb.astar();
    return 0;
}

