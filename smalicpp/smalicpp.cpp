// smalicpp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "smalicpp.h"
#include "JavaClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����:  MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  �ڴ˴�ΪӦ�ó������Ϊ��д���롣
			CJavaClass cJavaClass;
			//cJavaClass.AnalyzeClassSmali(CString(_T("F:\\out\\XTCBinding\\smali\\com\\xtc\\binding\\MainActivity.smali")));
			cJavaClass.AnalyzeClassSmali(CString(_T("E:\\Launcher\\HelloJavaCpp\\app\\build\\outputs\\apk\\debug\\app-debug\\smali\\com\\eebbk\\hellojavacpp\\MainActivity.smali")));

			cJavaClass.OutputCppFile();
			cJavaClass.OutputHeadFile();
			cJavaClass.OutputDependOnHeadFile();

			printf("���������س��˳�\n");
			getchar();
		}
	}
	else
	{
		// TODO:  ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����:  GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
