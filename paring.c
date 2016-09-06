#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>

char*id_getway[100];
int b;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}
char**take(char* server, char* user ,char* password ,char* dbname,char* nm_table,char* kk)
{      
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, server, user, password, 
          dbname, 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
char select[100];
 sprintf(select,"select*from  %s where id_getway=%s",nm_table,kk); 
 if (mysql_query(con,select)) 
 { 
      finish_with_error(con);
 }


 MYSQL_RES *result = mysql_store_result(con);  
 if (result == NULL) 
 {
      finish_with_error(con);
 }

int num_fields = mysql_num_fields(result);
MYSQL_ROW row;
int i;
int a=0;
{
   while(row = mysql_fetch_row(result))
    {
     for (i = 0; i < num_fields; i++)
        {
      b = a+i;     
      id_getway[b]=row[i];
        printf("data_library:%s %d\n",id_getway[b],b);
        }
	a=a+i;
  printf("\n"); 
    }
}

}

