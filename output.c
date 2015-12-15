void print_Enemies()
{ 
	for (int x=0; x<Battle.enemies; x++)
	{
		printf("%c %s\nHp: ",x==enemy_chosed? '[':' ', Battle->First.name[64]);
		for (int y=0; y<Battle->First.healh; y++)
			printf("*");
		for(int z=0; z<Battle->First.defence; z++)
			printf(")");
		printf("%c\n", x==enemy_chosed? ']':' ');
	}
}


void print_Items()	//solo nome 
{

}

