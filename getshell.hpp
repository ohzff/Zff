char* gshell(char db[])
{ 
    FILE *fp; 
    char* buffer; 

    fp=popen(db, "r"); 
    fgets(buffer,sizeof(buffer),fp); 
    //printf("%s",buffer); 

    return buffer;
}
