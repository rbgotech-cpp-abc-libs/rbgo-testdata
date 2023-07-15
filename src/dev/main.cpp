#ifdef RBGOTESTDATA_DEVMAIN
#include <stdlib.h>//setbuf, system, exit, atoi
#include <stdio.h>//puts, printf, scanf

#include <rbgo-testdata.h>
#include <rbgo-time.h>

void TstDsTblEspPs_show();

#define MENU_LENGTH 4
const char* menuStrings[MENU_LENGTH] = {
	"0	quit",
	"1	menu",
	"2	clear screen",

	"3	Show table: ESP Product Selector: "
};

int main(){

	rbgo::Sw64 *sw = new rbgo::Sw64();
	char input[16] = {0};
	rbgo::Tu32 mc=1, i=0;

	//---- Test case data alloc ----

	while(1){

		switch(mc){
		case 0: goto break2;
		case 1: mc=0; while(mc < MENU_LENGTH) puts(menuStrings[mc++]); break;
		case 2: system("cls | clear"); break;

		//---- Test case exec ----
		case 3:
			TstDsTblEspPs_show();
		break;
		}

		if(2 < mc && mc < MENU_LENGTH)
			sw->stopp(menuStrings[mc], "s\n");

		printf("choice: ");
		scanf("%2s", input);
		mc = atoi(input);
		sw->start();
	}

break2://---- Test case data free ----
	delete sw;

}



void TstDsTblEspPs_show(){

	using namespace rbgo;

	TstDsTblEspPs *t;
	Tu8 cols, ci;
	const char *sep, **fms, **cns, **row;
	
	t = new TstDsTblEspPs;
	cols = t->colCount();
	sep = t->rowSep();
	fms = t->rowFms();
	cns = t->colNames();

	puts(sep);
	ci = 0;
	while(ci < cols){
		printf(fms[ci], cns[ci]);
		ci++;
	}
	printf("\n%s\n", sep);

	t->iterate(true);
	while(row = t->iterate()){
		ci = 0;
		while(ci < cols){
			printf(fms[ci], row[ci]);
			ci++;
		}
		puts("");
	}

	printf("%s\n", sep);

	delete t;
}

#endif//RBGOTESTDATA_DEVMAIN
