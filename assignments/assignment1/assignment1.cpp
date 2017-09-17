#include <iostream>
#include <vector>

void display(const std::vector<int> &v)  // for single vector
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i) << ' ';
    }
}
void displaytwod(std::vector< std::vector<int> > &v3,int m) // for 2 d vector and nice output
{
    for(int a = 0; a < m; a++)
    {
       v3.at(a).at(0) = a;
    }
    for(unsigned i = 0; i < v3.size(); i++)
    {
        std::cout << v3.at(i).at(0) << " => " << v3.at(i).at(1) << "  ";
    }
}
void iterate(std::vector< std::vector<int> > &v3,const std::vector<int> &v2) // helper function for fibmod
{
    for(unsigned i = 0; i < v2.size(); i++)
    {
        int a = v2.at(i);
        v3.at(a).at(1) += 1;
    }
}
int findpos(const std::vector<int> &v,int &start,int &next) // helper function for fibmod given params
{
    int pos = 0;
    do
    {
       unsigned begin = start + 2;
       for(unsigned i = begin; i < v.size(); i++)
       {
           if(begin == v.size() - 1)
           {
               pos = -1;
           }
           if(pos == 0)
           {
             if(v.at(i) == v.at(start))
             {
                if(v.at(i + 1) == v.at(next))
                {
                   pos = i;
                }
             }   
           }
       }
       if(pos == 0)
       {
           start++;
           next++;
       }
    }
    while(pos == 0);
    return pos;
}
std::vector<int> fibmod(int m) //given just the mod number with standard v(0) = 0, v(1) = 1
{
    std::vector<int> v;
    std::vector<int> v2;
    std::vector<int> v3;
    v.push_back(0);
    v.push_back(1);
    v2.push_back(0);
    v2.push_back(1);
    int a = 0;
    int b = m * m;
    int c = m * m * m;
    if(m <= 3)
    {
       for(int i = 2; i < c; i++)
       {
          a = (v.at(i - 1) + v.at(i - 2))%m;
          v.push_back(a);
       } 
    }
    else
    {
       for(int i = 2; i < b; i++)
       {
          a = (v.at(i - 1) + v.at(i - 2))%m;
          v.push_back(a);
       }
    }
    std::cout << std::endl;
    int counter = 0;
    for(int i = 2; i < b; i++)
    {
        v2.push_back(v.at(i));
        if(v.at(i) == 0)
        {
            counter++;
        }
        if(counter == 1)
        {
            if(i == b - 2)
            {
                std::cout << "No fibonaci sequence!" << std::endl;
                return v3;
            }
            if((v.at(i + 1) == v.at(1)) && (v.at(i + 2) == v.at(2)))
            {
                v2.pop_back();
                return v2;
            }
            else
            {
                counter = 0;
            }    
        }
    }
    return v3;
}
std::vector<int> fibmod(int first,int second,int m) // used when first two nums are specified along with mod num
{
    std::vector<int> v;
    std::vector<int> v2;
    std::vector<int> v3;
    v.push_back(first);
    v.push_back(second);
    int a = 0;
    int b = m * m;
    int c = m * m * m * m;
    if(m <= 3)
    {
       for(int i = 2; i < c; i++)
       {
          a = (v.at(i - 1) + v.at(i - 2))%m;
          v.push_back(a);
       } 
    }
    else
    {
       for(int i = 2; i < b; i++)
       {
          a = (v.at(i - 1) + v.at(i - 2))%m;
          v.push_back(a);
       }
    }
    std::cout << std::endl;
    int start = 0;
    int next = 1;
    int position = findpos(v,start,next);
    if(position == -1)
    {
        std::cout << "No fibonaci sequence!" << std::endl;
        return v3;
    }
    int check = 0;
    for(unsigned i = position; i < v.size(); i++)
    {
        if(start == position)
        {
            check = 1;
        }
        if(check == 0)
        {
           if(v.at(i) == v.at(start))
           {
              int a = v.at(i);
              v2.push_back(a);
           }
           if(v.at(i) != v.at(start))
           {
              check = 1;
           }
           start++;
        }
    }
    return v2;
}
void createpairs(std::vector< std::vector<int> > &v,int m)
{
    int position = m * m;  
    int m2 = 0;
    int counter = 0;
    for(int i = 0; i < position; i++)
    {
        do
        {
           v.at(i).at(0) = m2;
           counter++;
           i++;
        }
        while(counter != m);    
        counter = 0;
        i--;
        m2++;
    }
    int var = 0;
    for(int i = 0; i < position; i++)
    {
        do
        {
           v.at(i).at(1) = var;
           counter++;
           i++;
           var++;
        }
        while(counter != m);    
        counter = 0;
        i--;
        var = 0;
    }
}
void removeduplicates( std::vector< std::vector<int> > &v,const std::vector<int> &v2,int m)
{
    int j = 0;
    int l = m * m;
    for(unsigned i = 0; i < v2.size(); i++)
    {
        j = 0;
        if(i != (v2.size() - 1))
        {
            do
            {
               if(((v2.at(i) == v.at(j).at(0)) && (v2.at(i + 1) == v.at(j).at(1))))
               {
                  v.at(j).at(0) = -10;
                  v.at(j).at(1) = -10;
               }
               if(((v2.at(v2.size() - 1) == v.at(j).at(0)) && (v2.at(0) == v.at(j).at(1))))
               {
                  v.at(j).at(0) = -10;
                  v.at(j).at(1) = -10;
               }
               j++;
            }
            while(j != l);
        }
    }
}
void findnextremove(std::vector< std::vector<int> > &v,int &first,int &second)
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        for(unsigned j = 0; j < v.at(i).size(); j++)
        {
            if(v.at(i).at(j) != -10)
            {
                first = v.at(i).at(0);
                second = v.at(i).at(1);
                return;
            }
        }
    }
}
int alldone(std::vector< std::vector<int> > &v)
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        for(unsigned j = 0; j < v.at(i).size(); j++)
        {
            if(v.at(i).at(j) != -10)
            {
                return -2;
            }
        }
    }
    return -3;
}
int main()
{
    int counterval = 0;
    do
    {
        std::vector<int> v;
        std::vector<int> v2;
        int m = 0;
        do
        {
            std::cout << "Enter M value: " << std::endl;
            std::cin >> m;
            if(m < 2)
            {
                std::cout << "M must be two or higher!" << std::endl;
            }    
        }
        while(m < 2);
        int paircheck = 0;
        std::cout << "Do you want to remove all pairs?(1 yes/0 no):" << std::endl;
        std::cin >> paircheck;
        int first = 0;
        int input = 0;
        int second = 0;
        std::cout << "Do you want to specify any initial values?(1 yes/0 no): " << std::endl;
        std::cin >> input;
        if(input == 0)
        {
            std::cout << "Repeated sequence with appearances: ";  
            v = fibmod(m);
            display(v); 
            std::vector< std::vector<int> > v3(m, std::vector<int> (2, 0));
            iterate(v3,v);
            std::cout << "  ";
            displaytwod(v3,m);
            int w = m * m;
            std::vector< std::vector<int> > v7(w, std::vector<int> (2, 0));
            createpairs(v7,m);   
            removeduplicates(v7,v,m);
            if(paircheck == 0)
            {
                std::cout << std::endl;
            }
            if(paircheck == 1)
            {
                int p = 0;
                int x = 0;
                int y = 0;
                do
                {
                   p = alldone(v7);
                   if(p != -3)
                   {
                        findnextremove(v7,x,y);
                        v = fibmod(x,y,m);
                        std::cout << "Repeated sequence with appearances " << std::endl;
                        display(v); 
                        std::vector< std::vector<int> > v8(m, std::vector<int> (2, 0));
                        iterate(v8,v);
                        std::cout << "  ";
                        displaytwod(v8,m);
                        removeduplicates(v7,v,m);
                    }
               }
               while(p != -3);
               std::cout << std::endl;
               std::cout << "All pairs removed!" << std::endl;   
            }
        }
        else if(input == 1)
        {
            std::cout << "Enter first value: " << std::endl;
            std::cin >> first;
            std::cout << "Enter second value: " << std::endl;
            std::cin >> second;     
        
            std::cout << "Repeated sequence with appearances: ";  
            v2 = fibmod(first,second,m);
            display(v2); 
            std::vector< std::vector<int> > v4(m, std::vector<int> (2, 0));
            iterate(v4,v2);
            std::cout << "  ";
            displaytwod(v4,m);
            int w = m * m;
            std::vector< std::vector<int> > v5(w, std::vector<int> (2, 0));
            createpairs(v5,m);
            removeduplicates(v5,v2,m);
            if(paircheck == 0)
            {
                std::cout << std::endl;
            }
            if(paircheck == 1)
            {
                int p = 0;
                do
                {
                    p = alldone(v5);
                    if(p != -3)
                    {
                       findnextremove(v5,first,second);
                       v2 = fibmod(first,second,m);
                       std::cout << "Repeated sequence with appearances: " << std::endl;
                       display(v2); 
                       std::vector< std::vector<int> > v6(m, std::vector<int> (2, 0));
                       iterate(v6,v2);
                       std::cout << "  ";
                       displaytwod(v6,m);
                       removeduplicates(v5,v2,m);
                    }
                }
                while(p != -3);
                std::cout << std::endl;
                std::cout << "All pairs removed!" << std::endl;
            }
        }
        std::cout << "Press 1 to run again, zero to exit: " << std::endl;
        std::cin >> counterval;
    }
    while(counterval > 0);
    return 0;
}
