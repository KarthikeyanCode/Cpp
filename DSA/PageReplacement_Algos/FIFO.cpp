//FIFO page replacement algorithm

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

class page
{
    private:

    public:

        vector<int> page_ref; // page reference string
        vector<int> page_frame; //page frame 
}p1;

int main(void)
{
    int dum,size=0;
    int option;
    bool cache;
    while(1)
    {
        cout << "Choose: " << "\n";
        cout << "1. Run the program " << "\n";
        cout << "2. Exit " << "\n";
        cin >> option;
        switch (option)
        {
            case 1:
            {
                p1.page_ref.clear();
                p1.page_frame.clear();
                cout << "Enter the page reference string: " << "\n"; //page reference string 
                while(1)
                {
                    cout << "Enter the page index and enter -1 to exit" << "\n";
                    cin >> dum;
                    if(dum==-1)
                    {
                        break;
                    }
                    else
                    {
                        p1.page_ref.push_back(dum);
                    }
                }
                cout << "Enter the size of page frame" << "\n"; //page frame 
                cin >> size;
                for(int i=0;i<p1.page_ref.size();i++)
                {
                    cache = false;
                    for(int j=0;j<p1.page_frame.size();j++)
                    {
                        if(p1.page_ref[i] == p1.page_frame[j]) //cache hit
                        {
                            cache = true;
                            cout << p1.page_ref[i] << " -> " << " hit " << "\n";
                        }
                    }
                    if(cache == false) //cache miss 
                    {
                        cout << p1.page_ref[i] << " -> " << " miss " << "\n";
                        if(p1.page_frame.size()+1 <= size)
                        {
                            p1.page_frame.push_back(p1.page_ref[i]);
                        }
                        else
                        {
                            p1.page_frame.erase(p1.page_frame.begin());
                            p1.page_frame.push_back(p1.page_ref[i]);
                        }
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Thankyou" << "\n";
                goto exit;
                break;
            }
            default:
            {
                cout << "Enter only valid numbers " << "\n";
                continue;
            }
        }
    }
    exit:
    cout << "Closing the program" << "\n";
    return 0;
}