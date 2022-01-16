void START()
{
    LINKED *START = NULL;
    char c;
    int NUM, NUM1;
    while (1)
    {
        PRINT_LINE("#");
        OPTION();
        PRINT_LINE("#");
        cout << "-> ";
        cin >> c;
        PRINT_LINE("#");
        switch (c)
        {
        case '1':
            cout << "Enter integer number \n to end Enter -1\n";
            cin >> NUM;
            while (NUM != -1)
            {
                INSERT_DATA_SORTED(&START, NUM);
                cin >> NUM;
            }
            break;
        case '2':
            cout << "\nFORWORD ORDER\n";
            DISPLAY_FORWORD(&START);
            cout << "\nREVERCE ORDER\n";
            DISPLAY_REVERSE(&START);
            cout << "\n";
            break;
        case '3':
            DELETE_ALL(&START);
            break;
        case '4':
            cout << "ENTER NUMBER\n";
            cin >> NUM;
            INSERT_DATA_SORTED(&START, NUM);
            break;
        case '5':
            cout << "ENTER NUMBRE\n";
            cin >> NUM;
            DELETE_ITEM(&START, NUM);
            break;
        case '6':
            ELEMENT(&START);
            break;
        case '7':
            cout << "WHICH NUMBER SHOULD BR REPLACE\n";
            cin >> NUM;
            cout << "ENTER REPLACED NUMBER\n";
            cin >> NUM1;
            REPLACE(&START, NUM, NUM1);
            break;
        case '8':
            cout << "ENTER YOUR NUMBER\n";
            cin >> NUM;
            NUM1 = SEARCH_SORTED_LIST(&START, NUM);
            if(NUM1 == 0)
            {
                cout << "ITEM NOT FOUND\n";
            }
            else 
            cout << "ITEM FOUND AT " << NUM1 << endl;
        case '9':
            exit(0);
            break;
        default:
            cout << "INVALID INPUT\n";
            cout << "TRY AGAIN\n";
            break;
        }
    }
}