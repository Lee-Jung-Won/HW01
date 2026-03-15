
//#include "Item.h"
#include "Inventory.h"

//#if defined(_MSC_VER)
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#include <cstdlib>
//#endif

int main()
{
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        //Item Superitem("portion99", 9999);
        //Item Trashitem("portion90", -1);

        Inventory<Item>* itemInventory = new Inventory<Item>();
        for (int i = 0; i < 10; ++i)
        {
            itemInventory->Additem(Item("Item" + std::to_string(i), i * 100));
        }

        delete itemInventory;
        itemInventory = nullptr;
 
        return 0;
    }

}
