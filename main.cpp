#include "main.h"
bool console (List & active_list, int & cmd);
int main()
{
    List active_list;
    int cmd;
    console(active_list, cmd);
    return 0;
}

bool console (List & active_list, int & cmd)
{
    if(cmd = 0)
    {
        return false;
    }
    std::cout << std::endl;
    std::cout << "Welcome to the Olympic Stat Viewer for Hockey, Basketball, Soccer" << std::endl;
    std::cout << std::endl;
    std::cout << "0: Exit Program" << std::endl;
    std::cout << "1: Display All Sports Events" << std::endl;
    std::cout << "2: Display Hockey Event" << std::endl;
    std::cout << "3: Display Basketball Event" << std::endl;
    std::cout << "4: Display Soccer Event" << std::endl;
    std::cout << "5: Search for Gold Medals" << std::endl;
    std::cout << "6: Search for Silver Medals" << std::endl;
    std::cout << "7: Search for Bronze Medals" << std::endl;
    std::cin >> cmd;
    switch (cmd)
    {
    case 0:
    {
        return false;
        break;
    }
    case 1:
    {
        std::cout << "-- All Sports Events --" << std::endl;
        try
        {
            bool display_flag;
            display_flag = active_list.display();
            if(display_flag == false)
                throw display_flag;
        }
        catch(bool display_flag)
        {
            std::cout << "Error: Failed to Sports Events" << std::endl;
        }
        break;
    }
    case 2:
    {
        std::cout << "-- Hockey Event --" << std::endl;
        try
        {
            bool display_flag;
            display_flag = active_list.display_hockey();
            if(display_flag == false)
                throw display_flag;
        }
        catch(bool display_flag)
        {
            std::cout << "Error: Failed to Display Hockey Event" << std::endl;
        }
        catch(...)
        {
            std::cout << "Error: Display Failed" << std::endl;
        }
        break;
    }
    case 3:
    {
        std::cout << "-- Basketball Event --" << std::endl;
        try{
            bool display_flag;
            display_flag = active_list.display_basketball();
            if(display_flag == false)
                throw display_flag;
        }
        catch(bool display_flag)
        {
            std::cout << "Error: Failed to Display Basketball Event" << std::endl;
        }
        catch(...)
        {
            std::cout << "Error: Display Failed" << std::endl;
        }
        break;
    }
    case 4:
    {
        std::cout << "--Soccer Event--" << std::endl;
        try
        {
            bool display_flag;
            display_flag = active_list.display_soccer();
            if(display_flag == false)
            {
                throw display_flag;
            }
        }
        catch(bool display_flag)
        {
            std::cout << "Error: Failed to Display Soccer Event" << std::endl;
        }
        catch(...)
        {
            std::cout << "Error: Display Failed" << std::endl;
        }
        break;
    }
    case 5:
    {
        std::cout << "--Gold Medals--" << std::endl;
        try 
        {
            bool medal_flag;
            medal_flag = active_list.search(1);
            if(medal_flag == false)
                throw medal_flag;
        }
        catch(bool flag)
        {
            std::cout << "Error: Search for Gold Medals Failed" << std::endl;
        }
        catch(...)
        {
            std::cout << "Error: Search Failed" << std::endl;
        }
        break;
    }
    case 6:
    {
        std::cout << "--Silver Medals--" << std::endl;
        try 
        {
            bool medal_flag;
            medal_flag = active_list.search(2);
            if(medal_flag == false)
                throw medal_flag;
        }
        catch(bool flag)
        {
            std::cout << "Error: Search for Gold Medals Failed" << std::endl;
        }
        catch(...)
        {
            std::cout << "Error: Search Failed" << std::endl;
        }
        break;
    }
    case 7:
    {
        std::cout << "--Bronze Medals--" << std::endl;
        try 
        {
            bool medal_flag;
            medal_flag = active_list.search(3);
            if(medal_flag == false)
                throw medal_flag;
        }
        catch(bool flag)
        {
            std::cout << "Error: Search for Gold Medals Failed" << std::endl;
        }
        catch(...)
        {
            std::cout << "Error: Search Failed" << std::endl;
        }
        break;
    }
    default:
        break;
    }
    return console(active_list, cmd);
}
    
