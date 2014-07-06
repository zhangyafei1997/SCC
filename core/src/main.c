
// test底层源码测试例程

#include "lex.h"
#include "parse.h"
#include "gen.h"

char filename[40];
bool isSinglePass;
bool isClickExe = false ;

static void ParseCmdLine(int argc, char *argv[]){
    ASSERT(argc==1);
    strcpy(filename,argv[0]);
}

int main(int argc, char *argv[]) { // 命令行获取文件名，可以设置输出文件。

// 如果是点击exe触发的，则需要在打印完输出后等待用户，否则黑窗口一闪而过不友好，如果出现错误，则也需要等待，断言错误不会发生，不用再断言里添加等待。
    isClickExe = false;
    if (argc <= 1){
		//ShowHelp();
		isClickExe = true;
		printf("Input filename:");
		scanf("%s",filename);
	}
	else ParseCmdLine(--argc, ++argv);

    isSinglePass = true;//false;

    if(isSinglePass){
        Gen_run(filename);
    }
    else{
        // 多遍分析由两个相互独立的模块组成，输入文件处理后输出文件 由于没有编写配置功能，所以未编写多遍部分
        Lex_run(filename,"lex.txt");
        //Parse_run("lex.txt","code.txt");
    }
    /*if(isClickExe){
        printf("输出完成，按任意键退出");
        getch();
    }*/
    return 0;
}
