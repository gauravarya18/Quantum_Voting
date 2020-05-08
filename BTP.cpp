#include <bits/stdc++.h>

using namespace std;
// hey budd
vector<string> sigmaX(vector<string>s,int pos)
{
    vector<string>retData;

    for(int i=0;i<s.size();i++)
    {
        string curr=s[i];
        curr[pos]=='0'?curr[pos]='1':curr[pos]='0';
        retData.push_back(curr);
    }

    return retData;
}

vector<string> sigmaY(vector<string>s,int pos)
{
    vector<string>retData;

    for(int i=0;i<s.size();i++)
    {
        string curr=s[i];
        curr[pos]=='0'?curr[pos]='1':curr[pos]='0';

        if(curr[pos]=='0')
        {
            curr[0]=='0'?curr[0]='1':curr[0]='0';
        }
        retData.push_back(curr);
    }

    return retData;
}

vector<string> sigmaZ(vector<string>s,int pos)
{
    vector<string>retData;

    for(int i=0;i<s.size();i++)
    {
        string curr=s[i];

        if(curr[pos]=='1')
        {
            curr[0]=='0'?curr[0]='1':curr[0]='0';
        }
        retData.push_back(curr);
    }

    return retData;
}


void mainfun(vector<string> &t,int i,int k)
{
    if(k==1)
      t=sigmaX(t,i);
    else if(k==2)
      t=sigmaY(t,i);
    else if(k==3)
     t=sigmaZ(t,i);


}

void printMap(map<vector<string>,vector< vector<int> > >A)
{
    cout<<A.size()<<"\n";
    for(map<vector<string>,vector< vector<int> > >::iterator i=A.begin();i!=A.end();i++)
    {
        vector<string>x=i->first;

        for(int j=0;j<x.size();j++)
        {
            for(int k=0;k<x[j].length();k++)
            {
                if(k==0 && x[j][k]=='0')
                cout<<" + ";
                else if(k==0 && x[j][k]=='1')
                cout<<" - ";
                else
                {
                    cout<<x[j][k];
                }

            }
            cout<<"      ";
        }


        vector< vector<int> >B=i->second;
        for(int j=0;j<B.size();j++)
        {
            cout<<"{";
            for(int d=0;d<B[j].size();d++)
            {
                if(B[j][d]==1)
                cout<<"X";
                else
                if(B[j][d]==2)
                cout<<"Y";
                else
                if(B[j][d]==3)
                cout<<"Z";
                else
                if(B[j][d]==0)
                cout<<"I";
            }
            cout<<"}|";
        }

        cout<<endl;
    }
}
map<vector<string>, vector< vector<int> > > m;
void recur(int x,int y,vector<string> A ,vector<int> C)
{
   if(x==0)
   {
       m[A].push_back(C);
    //   for(int i=0;i<A.size();i++)
    //     cout<<A[i]<<" ";
    //   for(int i=0;i<C.size();i++)
    //     cout<<C[i]<<" ";
    //     cout<<"\n";
       return;
   }

   for(int i=0;i<4;i++)
   {
       vector<string> B=A;
       mainfun(B,y,i);
       C.push_back(i);
       recur(x-1,y+1,B,C);
       C.erase(C.begin()+C.size()-1);
   }

   return;
}
bool xyz(vector<string> A,int l)
{
    // vector<string> A;
    // int n;
    // cin>>n;
    // int l;
    // while(n>0)
    // {
    //     string s;
    //     cin>>s;
    //     l=s.length();
    //     A.push_back(s);
    //     n--;
    // }



    m.clear();
    vector<int> C;
    recur(l,2,A,C);

    // for(int i=0;i<4;i++)
    //   {
    //       vector<int> temp;
    //       vector<string> B=A;
    //       mainfun(B,2,i);
    //       temp.push_back(i);

    //       for(int j=0;j<4;j++)
    //       {
    //          vector<string> C=B;
    //          mainfun(C,3,j);
    //          temp.push_back(j);

    //           for(int k=0;k<4;k++)
    //           {
    //             vector<string> D=C;
    //             mainfun(D,4,k);
    //             temp.push_back(k);
    //             m[D].push_back(temp);
    //             temp.erase(temp.begin()+temp.size()-1);
    //           }

    //          temp.erase(temp.begin()+temp.size()-1);
    //       }

    //       temp.erase(temp.begin()+temp.size()-1);

    //   }

   /// map printing ka apne isme likh
   // m set ka likh rha
   //phir paste krdiyo
   if(m.size()==pow(4,l))
     {
         printMap(m);
        //  vector<string> x=A;
        //  for(int j=0;j<x.size();j++)
        // {
        //     for(int k=0;k<x[j].length();k++)
        //     {
        //         if(k==0 && x[j][k]=='0')
        //         cout<<" + ";
        //         else if(k==0 && x[j][k]=='1')
        //         cout<<" - ";
        //         else
        //         {
        //             cout<<x[j][k];
        //         }

        //     }
        //     cout<<"  ";
        // }
        // cout<<"\n";
         return true;
     }

     return false;
}

string getBinary(int n,int m)
{
    string ans="";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans+="1";
        else
            ans+="0";
    }

    return "0"+ans.substr(32-m,m);
}
vector<vector<string> >ans;
void choose(int i,vector<string>A,vector<string>temp,int n)
{
    if(i>=A.size() || temp.size()>n)
        return;

    temp.push_back(A[i]);
    if(temp.size()==n)
    {
        // cout<<i<<"-->"<<temp.size()<<"  here"<<endl;
        ans.push_back(temp);
    }


    // cout<<i<<"-->"<<temp.size()<<endl;
    choose(i+1,A,temp,n);

    temp.pop_back();

    choose(i+1,A,temp,n);

    return;
}
void writeFile(int n)
{
    vector<string>data;
    for(int i=0;i<=pow(2,n)-1;i++)
    {
        data.push_back(getBinary(i,n));
    }
    // for(int i=0;i<data.size();i++)
    // cout<<data[i]<<endl;

    vector<string>temp;
    choose(0,data,temp,pow(2,n-1));

}

int main()
{
    int n;
    cin>>n;
    
    // writeFile(n);
    // //cout<<ans.size()<<" Number of states"<<endl;
    // for(int i=0;i<ans.size();i++)
    // {
    //     vector<string> t;
    //     for(int j=0;j<ans[i].size();j++)
    //         {
    //             t.push_back(ans[i][j]);
    //         }
    //     if(xyz(t,n-1))
    //         cout<<"###";
    // }
    


//i am
    int l;
    vector<string> A;
    while(n>0)
    {
       string s;
       cin>>s;
       l=s.length();
       A.push_back(s);
       n--;
    }

    bool t=xyz(A,l-2);

}
