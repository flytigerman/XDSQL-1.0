#pragma comment(lib,"initSQL.lib")
#pragma comment(lib,"QueryProcessor_complicated.lib")
#include "initSQL.h"
#include "QueryProcessor.h"
#include "gram.tab.h"




/* ≤‚ ‘ƒ£øÈ */
int main(void) {
	/*≥ı ºªØ*/
	MetaDataManager mdm=initSQL::init();
	QueryProcessor::init(&mdm);

	cout << endl<<"SQL>>" ;
	int i = 0;

	while (yyparse()!=0) { }

	return 0;
}