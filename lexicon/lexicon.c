//
// Created by mazin on 12.03.2025.
//


const char* HELLO_MESSAGE = "Добро пожаловать в наше приложение!\n\n";
const char* INFO_OF_APP = "В нашем приложении вы сможете взаимодействовать с таблицей продуктов. "
                          "Она имеет 6 полей: идентификационный номер (PK), название, описание, "
                          "цена, количество и номер категории, к которой относится данный продукт. "
                          "В приложении есть функции добавления продукта, удаления (по id) продукта, "
                          "сохранения таблицы, загрузка существующей таблицы (имеющей такие поля), "
                          "сортировка по одному из полей и вывод таблицы на экран\n\n";
const char* CHOOSE_ACT = "Чтобы выбрать одно из действий введите соответствующую команду "
                         "(на английском языке):\n1. Добавить продукт - add_product\n2. Удалить продукт "
                         "- delete_product\n3. Сохранить текущую таблицу - save_table\n4. Загрузить таблицу "
                         "- load_table\n5. Сортировка - sort_table\n6. Показать текущую таблицу - print_table\n"
                         "Чтобы выйти из приложения введите exit в данном меню\n";
const char* ADD_PRODUCT = "add_product";
const char* DELETE_PRODUCT = "delete_product";
const char* SAVE_TABLE = "save_table";
const char* LOAD_TABLE = "load_table";
const char* SORT_TABLE = "sort_table";
const char* PRINT_TABLE = "print_table";

const char* HELP_MESSAGE = "Чтобы выбрать одно из действий введите соответствующую команду (на английском языке). "
                           "Если необходимо ввести вещественной число, то ввод вещественной части производится "
                           "через точку (.): 4.1\n"
                   "Чтобы выйти из приложения введите exit при выборе действий в меню\n";

const char* OTHER_MESSAGE = "Я тебя не понимаю";

const char* ERROR_CHOOSE_ACT = "\nERROR: Некорректная строка\n";
const char* ERROR_PRODUCT_LIST_PTR = "\nERROR: ссылка на NULL\n";
const char* PRODUCT_WAS_ADDED = "Продукт был успешно добавлен в таблицу";



