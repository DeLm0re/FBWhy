//Type definition of Light
typedef struct Light
{
    unsigned short int x;
    unsigned short int y;
    unsigned short int radius;
} Light;

//Type definition of Thief
typedef struct Thief
{
    unsigned short int x;
    unsigned short int y;
} Thief;

//Type definition of Money
typedef struct Money
{
    unsigned short int x;
    unsigned short int y;
} Money;

//Type definition of AllLights
typedef struct AllLights
{
    unsigned short int lenght;
    Light *lights;
} AllLights;

//Type definition of AllLights
typedef struct AllThieves
{
    unsigned short int lenght;
    Thief *thieves;
} AllThieves;

//Type definition of AllLights
typedef struct AllMoney
{
    unsigned short int lenght;
    Money *money;
} AllMoney;

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Light"
* 
* param :
*           int lenght : The lenght of our table we want to allocate
*
* return :
*           AllLights* : A pointer on a table of "Light"
*/
AllLights* createAllLights(int lenght);

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Thief"
* 
* param :
*           int lenght : The lenght of our table we want to allocate
*
* return :
*           AllThieves* : A pointer on a table of "Thief"
*/
AllThieves* createAllThieves(int lenght);

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Money"
* 
* param :
*           int lenght : The lenght of our table we want to allocate
*
* return :
*           AllMoney* : A pointer on a table of "Money"
*/
AllMoney* createAllMoney(int lenght);