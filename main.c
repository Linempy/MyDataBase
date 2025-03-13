#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "database/products.h"
#include "output/outputConsoleDB.h"
#include "database/tableColumn.h"
#include "database/productList.h"
#include "sorted/sortedByField.h"
#include "interactionFile/writeFile.h"
#include "service/splitString.h"
#include "interactionFile/readFile.h"
#include "interface/cli.h"
#include "lexicon/lexicon.h"


int main(void) {

    system("chcp 65001");
    size_t defaultSizeProdList = 4;
    size_t defaultSizeTableList = 6;
    bool processWork = true;

    ProductList products = createProductList(defaultSizeProdList);
    TableColumnList columns = createTableColumnList(defaultSizeTableList);
    IdGenerator productIdGenerator = {1};
    addDefaultProductColumns(&columns);
    char filename[64];


    printf("%s", HELLO_MESSAGE);
    printf("%s", INFO_OF_APP);

    while (processWork) {
        char message[255];
        if(chooseAct(message)) {
            CODE_HANDLER result = handlerMessage(&products, &columns,
                                                 message, &productIdGenerator, filename);
            if (result == 2) {
                freeProductList(&products);
                freeTableColumnList(&columns);
                break;
            }
        } else return 0;
    }

    return 0;
}
