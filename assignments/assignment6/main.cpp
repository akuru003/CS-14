#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

enum Status  // ACTIVE, UNDISCOVERED, DISCOVERED, COMPLETE
{
    ACTIVE, UNDISCOVERED, DISCOVERED, COMPLETE // 0,1,2,3
};
enum Type  // SOURCE,NONE,SINK
{
    SOURCE,NONE,SINK  // 0,1,2,
};
class vertexs // vertex type, status, counter
{
   public:
   string vertex;
   Type type1;
   Status status1;
   int counter3;
   vertexs(string a, Type b, Status c, int d)
   : vertex(a),type1(b),status1(c),counter3(d)
   {}
};
class edges // edge cap loc1 loc 2 flow newcap
{
   public:
   string edge;
   int cap;
   string location1;
   string location2;
   int flow;
   int newcap;
   edges(string a, int b, string c, string d, int e, int f)
   : edge(a), cap(b), location1(c), location2(d), flow(e), newcap(f)
   {}
  friend bool operator<(edges a, edges b)
  {
      if((a.cap == 0) && (b.cap == 0))
      {
          return (a.newcap < b.newcap);
      }
      return (a.cap < b.cap);
  }
};

void gothroughgraph(vector<vertexs> &v, vector<vertexs> &p, vector<edges> &b, priority_queue<edges> &c, vector<string> &names,int &flowrate, int &finanswer, vector<string> &order)
{
    // v p b v names flow rate finanswer order
   vector<string> names5;
   names5 = names;
   names.clear();
   int counter10 = 0;
   int counter11 = 0;
   string name = "";
   string name1 = "";
   string name2 = "";
   int tempcap = -1;
   for(unsigned int i = 0; i < names5.size(); i++)   // set flow from graph
   {
       string a;
       string b5;
       a = names5.at(i);
       if(i < names5.size() - 1)
       {
           b5 = names5.at(i + 1);
           for(unsigned int j = 0; j < b.size(); j++)
           {
               if((b.at(j).location1 == a) && (b.at(j).location2 == b5))
               {
                   b.at(j).flow = flowrate;
               }
           }
       }
       else
       {
           b5 = "";
       }
   }
   for(unsigned int i = 0; i < v.size(); i++)   // has starting source
   {
       if(v.at(i).type1 == 0)
       {
           name = v.at(i).vertex;
       }
   }
   int checkdone = 0;
   int firstime = 0;
   int skip = 0;
   do
   {
        for(unsigned int i = 0; i < v.size(); i++) // checking if done
        {
            if(v.at(i).type1 == 2)
            {
                if(v.at(i).status1 == 3)
                {
                    checkdone = 3;
                    finanswer = 0;
                }
            }
        }
        if(checkdone != 3)
        {
            if(firstime == 0)
            {
                vector<int> tempi;
                for(unsigned int i = 0; i < b.size(); i++)
                {
                    if((b.at(i).location1 == name) || (b.at(i).location2 == name))
                    {
                        counter10 = 0;
                        counter11 = 0;
                        if(b.at(i).location1 == name)
                        {
                            for(unsigned int o = 0; o < order.size(); o++)
                            {
                                if((order.at(o) == b.at(i).location1))
                                {
                                    counter10 = o;
                                }
                            }
                            for(unsigned int o = 0; o < order.size(); o++)
                            {
                                if((order.at(o) == b.at(i).location2))
                                {
                                    counter11 = o;
                                }
                            }
                        }
                        else if(b.at(i).location2 == name)
                        {
                            counter10 = 0;
                            counter11 = 0;
                            for(unsigned int o = 0; o < order.size(); o++)
                            {
                                if((order.at(o) == b.at(i).location2))
                                {
                                    counter10 = o;
                                }
                            }
                            for(unsigned int o = 0; o < order.size(); o++)
                            {
                                if((order.at(o) == b.at(i).location1))
                                {
                                    counter11 = o;
                                }
                            }
                        }
                        if(counter10 > counter11)
                        {
                           int tempvar = 0;
                           tempvar = b.at(i).cap + b.at(i).flow;
                           b.at(i).newcap = tempvar;
                           edges x(b.at(i).edge, 0, b.at(i).location1, b.at(i).location2,flowrate,tempvar);
                           c.push(x);
                           tempi.push_back(b.at(i).cap);
                        }
                        else if(counter10 < counter11)
                        {
                           int tempvar = 0;
                           tempvar = b.at(i).cap - b.at(i).flow;
                           b.at(i).newcap = tempvar;
                           edges x(b.at(i).edge, 0, b.at(i).location1, b.at(i).location2,flowrate,tempvar);
                           c.push(x);
                           tempi.push_back(b.at(i).cap);
                        }
                    }
                }
                for(unsigned int i = 0; i < tempi.size(); i++)
                {
                    if(tempi.at(i) > tempcap)
                    {
                        tempcap = tempi.at(i);
                    }
                }
                firstime++;
            }
            else
            {
                for(unsigned int i = 0; i < b.size(); i++)
                {
                    if((b.at(i).location1 == name) || (b.at(i).location2 == name))
                    {
                         for(unsigned int j = 0; j < p.size(); j++)
                        {
                            if(p.at(j).vertex == b.at(i).location1)
                            {
                                if(p.at(j).counter3 > 0)
                                {
                                    skip = 1;
                                }
                            }
                            if(p.at(j).vertex == b.at(i).location2)
                            {
                                if(p.at(j).counter3 > 0)
                                {
                                    skip = 1;;
                                }
                            }
                        }
                    }
                    if(skip != 1)
                    {
                         if((b.at(i).location1 == name) || (b.at(i).location2 == name))
                        {
                            int realcap = 0;
                            if(tempcap > b.at(i).cap)
                            {
                                realcap = b.at(i).cap;
                            }
                            else
                            {
                                realcap = tempcap;
                            }
                            counter10 = 0;
                            counter11 = 0;
                            if(b.at(i).location1 == name)
                            {
                                for(unsigned int o = 0; o < order.size(); o++)
                                {
                                    if((order.at(o) == b.at(i).location1))
                                    {
                                        counter10 = o;
                                    }
                                }
                                for(unsigned int o = 0; o < order.size(); o++)
                                {
                                    if((order.at(o) == b.at(i).location2))
                                    {
                                        counter11 = o;
                                    }
                                }
                            }
                            else if(b.at(i).location2 == name)
                            {
                                for(unsigned int o = 0; o < order.size(); o++)
                                {
                                    if((order.at(o) == b.at(i).location2))
                                    {
                                        counter10 = o;
                                    }
                                }
                                for(unsigned int o = 0; o < order.size(); o++)
                                {
                                    if((order.at(o) == b.at(i).location1))
                                    {
                                        counter11 = o;
                                    }
                                }
                            }
                            if(counter10 > counter11)
                            {
                               int tempvar = 0;
                               tempvar = realcap + b.at(i).flow;
                               b.at(i).newcap = tempvar;
                               edges x(b.at(i).edge, 0, b.at(i).location1, b.at(i).location2,flowrate,tempvar);
                               c.push(x);
                            }
                            else if(counter10 < counter11)
                            {
                               int tempvar = 0;
                               tempvar = realcap - b.at(i).flow;
                               b.at(i).newcap = tempvar;
                               edges x(b.at(i).edge, 0, b.at(i).location1, b.at(i).location2,flowrate,tempvar);
                               c.push(x);
                            }
                        }
                    }
                    skip = 0;
                }
            }
            for(unsigned int i = 0; i < v.size(); i++)
            {
                if(v.at(i).vertex == name)
                {
                    v.at(i).status1 = COMPLETE;
                    names.push_back(v.at(i).vertex);
                }
            }
            for(unsigned int i = 0; i < p.size(); i++)
            {
                if(p.at(i).vertex == name)
                {
                    p.at(i).counter3++;
                }
            }
            name2 = c.top().location2;
            name1 = c.top().location1;
            for(unsigned int i = 0; i < p.size(); i++)
            {
                if(p.at(i).vertex == name2)
                {
                    if(p.at(i).counter3 > 0)
                    {
                        name = name1;
                    }
                }
                if(p.at(i).vertex == name1)
                {
                    if(p.at(i).counter3 > 0)
                    {
                        name = name2;
                    }
                }
            }
            tempcap = c.top().newcap;
            for(unsigned int i = 0; i < p.size(); i++)
            {
                if(p.at(i).vertex == name)
                {
                    if(p.at(i).type1 == SINK)
                    {
                          flowrate = tempcap;
                    }
                }
            }
            c.pop();
        }
   }
   while(checkdone != 3);
}

int main(int argc, char **argv)
{
   if(argc != 2)
   {
      cout << "ERROR: Invalid program call." << endl;
      return 1;
   }
   int flowrate = 0;
   string input = argv[1];
   string temp = "";
   string temp2 = "";
   int counter = 0;
   temp2 = input.at(counter);
   while(temp2 != ".")
   {
       temp += temp2;
       counter++;
       temp2 = input.at(counter);
   }
   string outputfile1 = temp + ".out";
   ifstream in(NULL);
   ifstream in1(NULL);
   ofstream out(NULL);
   in.open(input.c_str());
   if(!in.is_open())          //input file
   {
      cout << "Error opening input file, ending program!" << endl;
      return 0;
   }
   in1.open(input.c_str());
   if(!in1.is_open())          //input file
   {
      cout << "Error opening input file, ending program!" << endl;
      return 0;;
   }
   out.open(outputfile1.c_str());
   if(!out.is_open())
   {
      cout << "Error opening output file 1, ending program!" << endl;
      return 0;;
   }
   vector<vertexs> v;
   vector<vertexs> p;
   vector<edges> b;
   vector<edges> d;
   priority_queue<edges> c;
   vector<string> order;
   vector<string> names;
   vector<string> names1;
   int numvertexs = 0;
   int numedges = 0;
   in >> numvertexs;
   in >> numedges;
   in1 >> temp2;
   in1 >> temp2;
   in1 >> temp2;
   string num;
   string edge1;
   int cap1 = 0;
   string loc1;
   string loc2;
   counter = 0;
   do
   {
       num = "";
       temp2 = "";
       in >> num;
       in1 >> temp2;
       counter++;
      if(((temp2 == "source") || (temp2 == "sink")) && (num != "source") && (num != "sink"))
      {
          if(temp2 == "source")
          {
              vertexs a(num,SOURCE,UNDISCOVERED,0);
              v.push_back(a);
              order.push_back(num);
          }
          else if(temp2 == "sink")
          {
              vertexs a(num,SINK,UNDISCOVERED,0);
              v.push_back(a);
              order.push_back(num);
          }
      }
      else
      {
           if((num != "source") && (num != "sink"))
           {
              vertexs a(num,NONE,UNDISCOVERED,0);
              v.push_back(a);
              order.push_back(num);
           }
      }
   }
   while(counter != numvertexs + 2);
   p = v;
   for(int i = 0; i < numedges; i++)
   {
       in >> edge1;
       in >> cap1;
       in >> loc1;
       in >> loc2;
       edges a(edge1,cap1,loc1,loc2,0,0);
       b.push_back(a);
   }
   d = b;
   int howmanytimes = 0;
   string name10;
   for(unsigned int i = 0; i < v.size(); i++)
   {
       if(v.at(i).type1 == SINK)
       {
           name10 = v.at(i).vertex;
       }
   }
   for(unsigned int i = 0; i < b.size(); i++)
   {
       if(b.at(i).location1 == name10)
       {
           howmanytimes++;
       }
       if(b.at(i).location2 == name10)
       {
           howmanytimes++;
       }
   }
   int howmanytimes2 = 0;
   howmanytimes2 = howmanytimes;
   string name = "";
   string name1 = "";
   string name2 = "";
   int tempcap = -1;
   for(unsigned int i = 0; i < v.size(); i++)   // has starting source
   {
       if(v.at(i).type1 == 0)
       {
           name = v.at(i).vertex;
       }
   }
   int checkdone = 0;
   int firstime = 0;
   int skip = 0;
   do
   {
        for(unsigned int i = 0; i < v.size(); i++) // checking if done
        {
            if(v.at(i).type1 == 2)
            {
                if(v.at(i).status1 == 3)
                {
                    checkdone = 3;
                }
            }
        }
        if(checkdone != 3)
        {
            if(firstime == 0)
            {
                vector<int> tempi;
                for(unsigned int i = 0; i < b.size(); i++)
                {
                    if((b.at(i).location1 == name) || (b.at(i).location2 == name))
                    {
                        edges x(b.at(i).edge, b.at(i).cap, b.at(i).location1, b.at(i).location2,0,0);
                        c.push(x);
                        tempi.push_back(b.at(i).cap);
                    }

                }
                for(unsigned int i = 0; i < tempi.size(); i++)
                {
                    if(tempi.at(i) > tempcap)
                    {
                        tempcap = tempi.at(i);
                    }
                }
                firstime++;
            }
            else
            {
                for(unsigned int i = 0; i < b.size(); i++)
                {
                    if((b.at(i).location1 == name) || (b.at(i).location2 == name))
                    {
                         for(unsigned int j = 0; j < p.size(); j++)
                        {
                            if(p.at(j).vertex == b.at(i).location1)
                            {
                                if(p.at(j).counter3 > 0)
                                {
                                    skip = 1;
                                }
                            }
                            if(p.at(j).vertex == b.at(i).location2)
                            {
                                if(p.at(j).counter3 > 0)
                                {
                                    skip = 1;;
                                }
                            }
                        }
                    }
                    if(skip != 1)
                    {
                         if((b.at(i).location1 == name) || (b.at(i).location2 == name))
                        {
                            int realcap = 0;
                            if(tempcap > b.at(i).cap)
                            {
                                realcap = b.at(i).cap;
                            }
                            else
                            {
                                realcap = tempcap;
                            }
                            edges x(b.at(i).edge, realcap, b.at(i).location1, b.at(i).location2,0,0);
                            c.push(x);
                        }
                    }
                    skip = 0;
                }
            }
            for(unsigned int i = 0; i < v.size(); i++)
            {
                if(v.at(i).vertex == name)
                {
                    v.at(i).status1 = COMPLETE;
                    names.push_back(v.at(i).vertex);
                }
            }
            for(unsigned int i = 0; i < p.size(); i++)
            {
                if(p.at(i).vertex == name)
                {
                    p.at(i).counter3++;
                }
            }
            name2 = c.top().location2;
            name1 = c.top().location1;
            for(unsigned int i = 0; i < p.size(); i++)
            {
                if(p.at(i).vertex == name2)
                {
                    if(p.at(i).counter3 > 0)
                    {
                        name = name1;
                    }
                }
                if(p.at(i).vertex == name1)
                {
                    if(p.at(i).counter3 > 0)
                    {
                        name = name2;
                    }
                }
            }
            tempcap = c.top().cap;
            for(unsigned int i = 0; i < p.size(); i++)
            {
                if(p.at(i).vertex == name)
                {
                    if(p.at(i).type1 == SINK)
                    {
                        out << "Flowrate: ";
                        flowrate = tempcap;
                        out << flowrate << endl;
                    }
                }
            }
            c.pop();
        }
   }
   while(checkdone != 3);
   int final = 0;
   int safe = 0;
   int final2 = 0;
   string a;
   string b1;
   string a2;
   string b2;
   unsigned int k = 0;
   for(unsigned int j = 0; j < names.size(); j++)  // removing vertex
   {
      final = 0;
      final2 = 0;
      safe = 0;
      a = names.at(j);
      if(j != names.size() - 1)
      {
           b1 = names.at(j + 1);
      }
      else
      {
          safe = 1;
          b1 = "";
      }
      if(safe != 1)
      {
          for(unsigned int i = 0; i < d.size(); i++)
          {
              if(final != 1)
              {
                  if((d.at(i).location1 == a) && (d.at(i).location2 == b1))
                  {
                      final = 1;
                  }
                  else if((d.at(i).location1 == "w") || (d.at(i).location2 == "w"))
                  {
                      final = 1;
                  }
                  else if((d.at(i).location1 == b1) && (d.at(i).location2 == a))
                  {
                      final = 1;
                  }
                  else
                  {
                      final = 0;
                  }
              }
          }
          if(final == 0)
          {
              if(j != names.size() - 1)
              {
                  j++;
                  a2 = names.at(j);
                  k = j;
              }
              if(j != names.size() - 1)
              {
                   b2 = names.at(j + 1);
                   j--;
              }
              else
              {
                  safe = 2;
                  b2 = "";
              }   
              if(safe != 2)
              {
                  for(unsigned int i = 0; i < d.size(); i++)
                  {
                      if(final2 != 1)
                      {
                          if((d.at(i).location1 == a2) && (d.at(i).location2 == b2))
                          {
                              final2 = 1;
                          }
                          else if((d.at(i).location1 == b2) && (d.at(i).location2 == a2))
                          {
                              final2 = 1;
                          }
                          else
                          {
                              final2 = 0;
                          }
                      }
                  }
                  if(final2 == 0)
                  {
                      for(unsigned int r = k; r < names.size() - 1; r++)
                      {
                          names.at(r) = names.at(r + 1);
                      }
                      names.at(names.size() - 1) = "w";
                  }
              }

          }
      }
  }
   out << "Path: ";
   for(unsigned int i = 0; i < names.size(); i++)  // output to file
   {
       if(names.at(i) != "w")
       {
         out << names.at(i) << " ";
       }
   }
   out << endl;
   names1.clear();
   for(unsigned int i = 0; i < names.size(); i++) // remove w
   {
       if(names.at(i) != "w")
       {
           names1.push_back(names.at(i));
       }
   }
   names = names1;                // first iteration - flow 5
   int finanswer = -100;
   int totalflow = 0;
   totalflow += flowrate;
   while(howmanytimes != 0) // gets other flow rates and output
   {
       for(unsigned int i = 0; i < v.size(); i++) // reset
       {
           if(v.at(i).status1 == 3)
           {
               v.at(i).status1 = UNDISCOVERED;
           }
       }
       p = v;
       while(!c.empty())
       {
           c.pop();
       }
       gothroughgraph(v,p,b,c,names,flowrate,finanswer,order);
       if(flowrate > 0)
       {
          totalflow += flowrate;   
       }
       k = 0;
       d = b;
       for(unsigned int j = 0; j < names.size(); j++)  // removing vertex
       {
          final = 0;
          final2 = 0;
          safe = 0;
          a = names.at(j);
          if(j != names.size() - 1)
          {
               b1 = names.at(j + 1);
          }
          else
          {
              safe = 1;
              b1 = "";
          }
          if(safe != 1)
          {
              for(unsigned int i = 0; i < d.size(); i++)
              {
                  if(final != 1)
                  {
                      if((d.at(i).location1 == a) && (d.at(i).location2 == b1))
                      {
                          final = 1;
                      }
                      else if((d.at(i).location1 == "w") || (d.at(i).location2 == "w"))
                      {
                          final = 1;
                      }
                      else if((d.at(i).location1 == b1) && (d.at(i).location2 == a))
                      {
                          final = 1;
                      }
                      else
                      {
                          final = 0;
                      }
                  }
              }
              if(final == 0)
              {
                  if(j == names.size() - 2)
                  {
                      string b13 = names.at(j + 1);
                      names.at(j) = b13;
                      names.at(j + 1) = "w";
                      safe = 2;
                  }
                  if(j != names.size() - 1)
                  {
                      j++;
                      a2 = names.at(j);
                      k = j;
                  }
                  if(j != names.size() - 1)
                  {
                       b2 = names.at(j + 1);
                       j--;
                  }
                  else
                  {
                      safe = 2;
                      b2 = "";
                  }
                  if(safe != 2)
                  {
                      for(unsigned int i = 0; i < d.size(); i++)
                      {
                          if(final2 != 1)
                          {
                              if((d.at(i).location1 == a2) && (d.at(i).location2 == b2))
                              {
                                  final2 = 1;
                              }
                              else if((d.at(i).location1 == b2) && (d.at(i).location2 == a2))
                              {
                                  final2 = 1;
                              }
                              else
                              {
                                  final2 = 0;
                              }
                          }
                      }
                      if(final2 == 0)
                      {
                          for(unsigned int r = k; r < names.size() - 1; r++)
                          {
                              names.at(r) = names.at(r + 1);
                          }
                          names.at(names.size() - 1) = "w";
                      }
                  }
              }
          }
      }
       if(flowrate > 0) // output flow and path
       {
           out << "Flowrate: ";
           out << flowrate << endl;
           out << "Path: ";
           for(unsigned int i = 0; i < names.size(); i++)  // output to file
           {
               if(names.at(i) != "w")
               {
                 out << names.at(i) << " ";
               }
           }
           out << endl;  
       }
       names1.clear();
       for(unsigned int i = 0; i < names.size(); i++) // remove w
       {
           if(names.at(i) != "w")
           {
               names1.push_back(names.at(i));
           }
       }
       names = names1;
       howmanytimes--;
   }
   out << "Maxflow: " << totalflow << endl;
   howmanytimes = howmanytimes2 + 1;
   for(unsigned int i = 0; i < v.size(); i++)   // has starting source
   {
       if(v.at(i).type1 == 0)
       {
           name = v.at(i).vertex;
       }
   }
   int counter50 = 1;
   int addup = 0;
   int temp11 = 10000000;
   int pos = 0;
   vector<int> ou;
   for(unsigned int i = 0; i < b.size(); i++) // pushback vales
   {
       if((b.at(i).location1 == name) || (b.at(i).location2 == name))
       {
            ou.push_back(b.at(i).newcap);
       }
   }
   for(unsigned int i = 0; i < ou.size(); i++) // add vals
   {
       addup += ou.at(i);
   }
   if(addup < totalflow)
   {
       while(addup < totalflow)
       {
           addup = 0;
           for(unsigned int i = 0; i < ou.size(); i++)
           {
               if(ou.at(i) < temp11)
               {
                   temp11 = ou.at(i);
                   pos = i;
               }
           }
           ou.at(pos)++;
           for(unsigned int i = 0; i < ou.size(); i++) // add vals
           {
               addup += ou.at(i);
           }
       }
   }
   for(unsigned int i = 0; i < ou.size(); i++)
   {
       out << "Path " << counter50 << " flow: " << ou.at(i) << endl; 
       counter50++;
   }
   in.close();
   in1.close();
   out.close();
   return 0;
}

