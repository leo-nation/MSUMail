/*

imaps_stat.cpp
--------------
  
Connects to IMAP server and gets number of messages in mailbox.


Copyright (C) 2016, Tomislav Karastojkovic (http://www.alepho.com).

Distributed under the FreeBSD license, see the accompanying file LICENSE or
copy at http://www.freebsd.org/copyright/freebsd-license.html.

*/


#include <iostream>
#include <mailio/imap.hpp>
#include <string.h>

using mailio::imaps;
using mailio::imap_error;
using mailio::dialog_error;
using std::cout;
using std::cin;
using std::endl;
std::string password;
int main()
{
    try
    {
        // connect to server
        imaps conn("imap.gmail.com", 993);
        // modify to use an existing gmail account
        cout << "Enter Password: " << endl;
        cin >> password;
        conn.authenticate("nilezwalker@gmail.com", password, imaps::auth_method_t::LOGIN);
        // query inbox statistics
        imaps::mailbox_stat_t stat = conn.statistics("inbox");
        mailio::message msg;
        // conn.fetch("inbox", 1, msg);
        // cout << msg.from_to_string();
        cout << "Number of messages in mailbox: " << stat.messages_no << endl;
        
    }
    catch (imap_error& exc)
    {
        cout << exc.what() << endl;
    }
    catch (dialog_error& exc)
    {
        cout << exc.what() << endl;
    }

    return EXIT_SUCCESS;
}
