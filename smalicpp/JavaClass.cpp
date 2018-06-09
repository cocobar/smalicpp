#include "stdafx.h"
#include "JavaClass.h"
#include "JavaMethod.h"




CJavaClass::CJavaClass()
{
	listExternClassList.clear();
}


CJavaClass::~CJavaClass()
{
}

CString CJavaClass::GetCppTypeFromJava(CString strType) {
	int nArrayCount = 0;
	bool bIsClassType = false;
	CString strTypeString;

	if (strType.Find("[") == 0) {
		for (int i = 0; i < strType.GetLength(); i++) {
			if (strType[i] == '[') {
				nArrayCount++;
			}
			else {
				strType = strType.Right(strType.GetLength() - nArrayCount);
				break;
			}
		}
	}


	/*
	case 'B':   return "byte";
	case 'C':   return "char";
	case 'D':   return "double";
	case 'F':   return "float";
	case 'I':   return "int";
	case 'J':   return "long";
	case 'S':   return "short";
	case 'V':   return "void";
	case 'Z':   return "boolean";
	case 'L':
	*/
	if (strType.Compare("B") == 0) {
		strTypeString = CString("unsigned char");
	}
	else if (strType.Compare("C") == 0) {
		strTypeString = CString("char");
	}
	else if (strType.Compare("D") == 0) {
		strTypeString = CString("double");
	}
	else if (strType.Compare("F") == 0) {
		strTypeString = CString("float");
	}
	else if (strType.Compare("I") == 0) {
		strTypeString = CString("int");
	}
	else if (strType.Compare("J") == 0) {
		strTypeString = CString("long");
	}
	else if (strType.Compare("S") == 0) {
		strTypeString = CString("short");
	}
	else if (strType.Compare("V") == 0) {
		strTypeString = CString("void");
	}
	else if (strType.Compare("Z") == 0) {
		strTypeString = CString("bool");
	}
	else if (strType.Find("L") == 0){
		strTypeString = strType;
#if 1
		strTypeString.Replace('/', '_');
		strTypeString.Replace('$', '_');
		strTypeString.Replace(';', ' ');
#else
		strTypeString.Remove('/');
		strTypeString.Remove('$');
		strTypeString.Remove(';');
#endif
		strTypeString.Trim();
		strTypeString = strTypeString.Right(strTypeString.GetLength() - 1);
		bIsClassType = true;
	}
	else {
		printf("未知的类型 %s \n", strType);
		strTypeString = CString("UnknowType");
	}

	if (bIsClassType) {
		listExternClassList.push_back(strTypeString);
	}

	// 用Cpp的vector来嵌套替代数组
#if 1
	while (nArrayCount--) {
		strTypeString = CString("std::vector<") + strTypeString + CString(">");
	}
#else
	while (nArrayCount--) {
		strTypeString += CString("[]");
	}
#endif

	return strTypeString;
}

// 返回类型列表
std::vector<CString> CJavaClass::GetFieldSymbolList(CString strLine) {
	std::vector<CString> listSymbol;

	BOOL bInString = false;
	BOOL bChangeSymbol = false;
	CString strNote;

	listSymbol.clear();
	strLine += CString("  ");	// 优化一下下面的代码处理流程

	int nState = 0;
	for (int i = 0; i < strLine.GetLength(); i++) {
		char _c = strLine[i];

		switch (nState) {
		case 0:		// 刚开始
			strNote.Empty();

			if (
				((_c >= 'a') && (_c <= 'z')) || ((_c >= 'A') && (_c <= 'Z')) ||
				(_c == '_') || (_c == '.') || (_c == '[')
				)
			{
				strNote += _c;
				nState = 1;  // 进入标准符号
			}
			else if (
				_c == '\''
				) {
				strNote += _c;
				nState = 2;	 // 进入字节内容
			}
			else if (
				_c == '\"'
				) {
				strNote += _c;
				nState = 3;	 // 进入文本内容
			}
			else if (
				(_c == '=') || (_c == '+') || (_c == '-')
				)
			{
				strNote += _c;
				nState = 4;	 // 进入符号
			}
			else if ((_c >= '0') && (_c <= '9')) {
				strNote += _c;
				nState = 5;	 // 进入数字
			}
			else if ((_c == ' ') || (_c == '\t'))
			{
				//  这里是合法的空格
			}
			else {
				printf("Unknow Symbol %c at %d of %s\n", _c, i, strLine.GetBuffer());
				strLine.ReleaseBuffer();
			}
			break;
		case 1:	// 标准符号
			if (
				((_c >= 'a') && (_c <= 'z')) || ((_c >= 'A') && (_c <= 'Z')) || ((_c >= '0') && (_c <= '9')) ||
				(_c == '_') || (_c == '&') || (_c == '/') || (_c == ':') || (_c == ';') || (_c == '.') || (_c == '[')
				)
			{
				strNote += _c;
			}
			else {
				i--; nState = 0;
				strNote.Trim();
				listSymbol.push_back(strNote);
			}

			break;
		case 2:	// 进入字节内容

			if (bChangeSymbol) {
				strNote += _c;
				bChangeSymbol = false;
			}
			else {
				if ((_c == '\\'))
				{
					strNote += _c;
					bChangeSymbol = true;
				}
				else if ((_c == '\''))
				{
					strNote += _c;
					i--; nState = 0;
					strNote.Trim();
					listSymbol.push_back(strNote);
				}
				else {
					strNote += _c;
				}
			}

			break;

		case 3:	// 进入字串内容

			if (bChangeSymbol) {
				strNote += _c;
				bChangeSymbol = false;
			}
			else {
				if ((_c == '\\'))
				{
					strNote += _c;
					bChangeSymbol = true;
				}
				else if ((_c == '\"'))
				{
					strNote += _c;
					i--; nState = 0;
					strNote.Trim();
					listSymbol.push_back(strNote);
				}
				else {
					strNote += _c;
				}
			}
			break;

		case 4:	// 进入符号
		{
			CString strTmp = (strNote + _c);

			if ((strTmp.Compare("++") == 0) || (strTmp.Compare("+=") == 0) || (strTmp.Compare("--") == 0) || (strTmp.Compare("-=") == 0) || (strTmp.Compare("==") == 0)) {
				strNote += _c;
				nState = 0;
				strNote.Trim();
				listSymbol.push_back(strNote);
			}
			else {
				i--; nState = 0;
				strNote.Trim();
				listSymbol.push_back(strNote);
			}

		}
			break;
		case 5:	// 进入数字
			if (
				((_c >= '0') && (_c <= '9')) ||
				(_c == 'x') || (_c == 'X') || (_c == 'l') || (_c == 'L') || (_c == '.')
				)
			{
				strNote += _c;
			}
			else {
				i--; nState = 0;
				strNote.Trim();
				listSymbol.push_back(strNote);
			}

			break;
		}
	}

	return listSymbol;
}



// 开始处理单个 Smali 文件
BOOL CJavaClass::AnalyzeClassSmali(CString strSmaliFile) {

	CStdioFile cStdFile;

	if (cStdFile.Open(strSmaliFile, CFile::modeRead)) {
		CString strLine;

		while (cStdFile.ReadString(strLine)) {

			if (strLine.Trim().GetLength() > 0) {

				if (strLine.Find("#") == 0) {						// 这个是注释行
					printf("处理 %s\n", strLine);
				}
				else if (strLine.Find(".class") == 0) {				// 找到当前Class的名称
					int nFindL = strLine.Find("L");
					if (nFindL > 0) {
						strClassName = GetCppTypeFromJava(strLine.Right(strLine.GetLength() - nFindL));
						//strClassName = CJavaClass::GetCppTypeFromJava(strLine.Right(strLine.GetLength() - nFindL));
					}
					else {
						strClassName = CString("Unknow_Class_Name");
						printf("Class 名称处理错误\n");
					}
				}
				else if (strLine.Find(".super") == 0) {				// 父类的名称
					int nFindL = strLine.Find("L");
					if (nFindL > 0) {
						strSuperName = GetCppTypeFromJava(strLine.Right(strLine.GetLength() - nFindL));
					}
					else {
						strSuperName = CString("Unknow_Class_Name");
						printf("Super 名称处理错误\n");
					}
				}
				else if (strLine.Find(".implements") == 0) {		// 实现
					int nFindL = strLine.Find("L");
					CString strImplement;
					if (nFindL > 0) {
						strImplement = strLine.Right(strLine.GetLength() - nFindL);
					}
					else {
						strImplement = CString("Unknow_Class_Name");
						printf("Implements 名称处理错误\n");
					}

					listStrImplements.push_back(strImplement);
				}
				else if (strLine.Find(".field") == 0) {				// 成员变量
					unsigned int accessFlags = 0;
					BOOL bHasEq = false;
					CString strNote;
					CString valType;
					CString valName;
					CString valValue;

					std::vector<CString> listSymbol = GetFieldSymbolList(strLine);
					std::vector<CString>::iterator it;
					for (it = listSymbol.begin(); it != listSymbol.end(); it++) {
						strNote = (*it);

						if (strNote.Find(".field") == 0) {
							//
						}
						else if (strNote.Find("private") == 0) {
							accessFlags |= ACC_PRIVATE;
						}
						else if (strNote.Find("static") == 0) {
							accessFlags |= ACC_STATIC;
						}
						else if (strNote.Find("final") == 0) {
							accessFlags |= ACC_FINAL;
						}
						else if (strNote.Find("public") == 0) {
							accessFlags |= ACC_PUBLIC;
						}
						else if (strNote.Find("protected") == 0) {
							accessFlags |= ACC_PROTECTED;
						}
						else if (strNote.Find("volatile") == 0) {
							accessFlags |= ACC_VOLATILE;
						}
						else if (strNote.Find("transient") == 0) {
							accessFlags |= ACC_TRANSIENT;
						}
						else if (strNote.Find("synthetic") == 0) {
							accessFlags |= ACC_SYNTHETIC;
						}
						else if (strNote.Find("enum") == 0) {
							accessFlags |= ACC_ENUM;
						}
						else if (strNote.Find("=") == 0) {
							bHasEq = true;
						}
						else if ((strNote.Find(":") > 0) && (bHasEq == false)) {
							int nFindDot = strNote.Find(":");
							valName = strNote.Left(nFindDot);
							valType = strNote.Right(strNote.GetLength() - nFindDot - 1);
							valName.Trim();
							valType.Trim();
						}
						else if (bHasEq) {
							valValue = strNote;
						}
						else {
							printf("未知符号 strNote = %s\n", strNote);
						}
					}

					// 补充成C++的代码
					CString cppString;

					if (accessFlags & ACC_PRIVATE) {
						cppString += CString("private ");
					}

					if (accessFlags & ACC_STATIC) {
						cppString += CString("static ");
					}

					if (accessFlags & ACC_FINAL) {
						cppString += CString("const ");
					}

					cppString += (GetCppTypeFromJava(valType) + CString(" ") + valName);
					if (bHasEq) {
						cppString += (CString(" = ") + valValue);
					}
					cppString += CString(";");
					printf("Cpp Code: %s\n", cppString);

					listStrFields.push_back(cppString);
				}
				else if (strLine.Find(".method") == 0) {				// 成员方法

					// 将整个method部分的代码放入 listMethodInst 数组
					std::vector<CString> listMethodInst;
					listMethodInst.clear();
					listMethodInst.push_back(strLine);

					CJavaMethod cJavaMethod;

					printf("###################################################################################################\n");
					printf("开始处理函数 %s\n", strLine);

					while (cStdFile.ReadString(strLine)) {
						if (strLine.Trim().GetLength() > 0) {			// 过滤掉空行
							listMethodInst.push_back(strLine);
							if (strLine.Find(".end method") == 0) {		// 结束位置，处理完结束
								break;
							}
							else if (strLine.Find(".locals") == 0)
							{
							}
							else {
								if (strLine.Find(":") == 0) {
								}
								else {
								}
							}
						}
					}

					// 处理Method数组
					cJavaMethod.strSuperClass = strSuperName;
					cJavaMethod.strClassName = strClassName;
					cJavaMethod.ProcessInstList(this, listMethodInst);

					listJavaMethods.push_back(cJavaMethod);
				}
				else if (strLine.Find(".end method") == 0) {
					printf("未成对处理的 method 结束\n");
				}
				else {
					printf("未处理的行 %s\n", strLine.GetBuffer());
					strLine.ReleaseBuffer();
				}
			}
		}
		cStdFile.Close();
	}

	sort(listExternClassList.begin(), listExternClassList.end());
	std::vector<CString>::iterator iter = std::unique(listExternClassList.begin(), listExternClassList.end());
	listExternClassList.erase(iter, listExternClassList.end());

	return TRUE;
}



// 生成CPP文件
BOOL CJavaClass::OutputCppFile() {

	printf("-->生成CPP文件\n");

	// 输出头文件
	for (unsigned int i = 0; i < listExternClassList.size(); i++) {
		printf("#include \"%s.h\"\n", listExternClassList[i]);
	}

	printf("\n");

	for (unsigned int i = 0; i < listJavaMethods.size(); i++) {
		for (unsigned int j = 0; j < listJavaMethods[i].listCppStringCode.size(); j++) {
			printf("%s\n", listJavaMethods[i].listCppStringCode[j]);
		}
	}

	return true;
}
// 生成头文件
BOOL CJavaClass::OutputHeadFile() {

	printf("-->生成CPP头文件\n");

	printf("#ifndef %s_H__\n", this->strClassName);
	printf("#define %s_H__\n", this->strClassName);

	for (unsigned int i = 0; i < listExternClassList.size(); i++) {
		printf("class %s;\n", listExternClassList[i]);
	}

	printf("class %s : public %s\n", this->strClassName, this->strSuperName);
	printf("{\n");
	printf("public:\n");
	for (unsigned int i = 0; i < this->listPublicMemberList.size(); i++) {
		printf("\t%s;\n", this->listPublicMemberList[i]);
	}
	printf("private:\n");
	for (unsigned int i = 0; i < this->listPrivateMemberList.size(); i++) {
		printf("\t%s;\n", this->listPrivateMemberList[i]);
	}
	printf("protected:\n");
	for (unsigned int i = 0; i < this->listProtectMemberList.size(); i++) {
		printf("\t%s;\n", this->listProtectMemberList[i]);
	}
	printf("};\n");
	printf("#endif\n");
	return true;
}
// 生成Java文件，这个Java文件里面直接包含包装器
BOOL CJavaClass::OutputJavaFile() {

	return true;
}
// 生成JNI接口 CPP文件，真的就是JNI接口文件, 头文件都不需要
BOOL CJavaClass::OutputJniCppFile() {

	return true;
}

CString CJavaClass::strGetJvmClassNameFromCallMethodString(CString strCallMethodString) {
	CString strClassName;
	strCallMethodString.Trim();
	int nDotPos = strCallMethodString.Find("->");
	if (nDotPos > 0) {
		strClassName = strCallMethodString.Left(nDotPos);
		strClassName.Trim();
	}
	if (strClassName.Trim().IsEmpty()) {
		printf("格式错误 %s  %d %s\n", strCallMethodString, __LINE__, __FILE__);
	}

	return strClassName;
}

CString CJavaClass::strGetJvmSignatureFromCallMethodString(CString strCallMethodString) {
	std::vector<CString> listString;
	strCallMethodString.Trim();
	listString.clear();
	CString strSignature;
	int nDotPos = strCallMethodString.Find("(");
	if (nDotPos > 0) {
		strSignature = strCallMethodString.Right(strCallMethodString.GetLength() - nDotPos).Trim();
	}

	return strSignature;
}


bool CJavaClass::InsertExternClassMethod(CString strCallMethodString, bool bIsStatic) {

	CJavaMethod cMethod;
	CJavaInstructItem cInstruct;
	CJavaExternClassMethod cClassMethod;
	cMethod.pClass = this;
	cInstruct.pMethod = &cMethod;

	//printf("%s\n", strCallMethodString);

	CString strMethodClassName = cInstruct.GetClassNameFromInstInvoke(strCallMethodString);
	std::vector<CString> listParamType = cInstruct.GetSignatureFromInstInvoke(strCallMethodString);
	CString strReturnName = cInstruct.GetReturnTypeFromInstInvoke(strCallMethodString);
	CString strFunctionName = cInstruct.GetMethodNameFromInstInvoke(strCallMethodString);

	CString strJvmClassName = this->strGetJvmClassNameFromCallMethodString(strCallMethodString);

	// 是否需要放入表格中, 作为外部引入的函数使用
	if (strMethodClassName != this->strClassName) {
		unsigned int nParamIndexTmp2 = 1;
		CString strExternMethod;
		if (bIsStatic) {
			strExternMethod = CString("static ");
			nParamIndexTmp2 = 0;
		}
		strExternMethod += (strReturnName + CString(" "));
		//strExternMethod += (strClassName + CString("::"));
		strExternMethod += (strFunctionName + CString("("));
		for (unsigned int em = 0; em < listParamType.size(); em++, nParamIndexTmp2++) {
			CString strTypeName = listParamType[em];
			CString strParamOne;
			strParamOne.Format("%s paramP%d", listParamType[em], nParamIndexTmp2);
			if (strTypeName.Compare("double") == 0) {
				nParamIndexTmp2++;
			}
			else if (strTypeName.Compare("long") == 0) {
				nParamIndexTmp2++;
			}
			strExternMethod += strParamOne;

			if ((em + 1) != listParamType.size()) {
				strExternMethod += CString(",");
			}
		}
		strExternMethod += CString(")");

		cClassMethod.strCppString = strExternMethod;
	}
	else {
		return true;
	}

	// 先填上这个结构体
	cClassMethod.bStatic = bIsStatic;
	cClassMethod.strCallString = strCallMethodString;
	cClassMethod.strName = strFunctionName;
	cClassMethod.listParam = listParamType;
	cClassMethod.strReturnType = strReturnName;

	// 寻找这个Class是不是已经存在了
	for (unsigned int i = 0; i < this->listExternClassInfo.size(); i++) {
		if (this->listExternClassInfo[i].strClassName == strMethodClassName) {
			this->listExternClassInfo[i].listMethod.push_back(cClassMethod);

			// 去重
			sort(this->listExternClassInfo[i].listMethod.begin(), this->listExternClassInfo[i].listMethod.end());
			std::vector<CJavaExternClassMethod>::iterator iter = std::unique(this->listExternClassInfo[i].listMethod.begin(), this->listExternClassInfo[i].listMethod.end());
			this->listExternClassInfo[i].listMethod.erase(iter, this->listExternClassInfo[i].listMethod.end());
			return true;
		}
	}

	{
		CJavaExternClass cExternClass;
		cExternClass.strClassName = strMethodClassName;
		cExternClass.strJvmClassName = strJvmClassName;
		cExternClass.listField.clear();
		cExternClass.listMethod.clear();
		cExternClass.listMethod.push_back(cClassMethod);
		listExternClassInfo.push_back(cExternClass);
	}

	return true;
}

bool CJavaClass::InsertExternClassField(CString strFieldString, bool bIsStatic) {

	CJavaMethod cMethod;
	CJavaInstructItem cInstruct;
	CJavaExternClassField cClassField;
	cMethod.pClass = this;
	cInstruct.pMethod = &cMethod;

	//printf("%s\n", strFieldString);

	CString strFiledClassName = cInstruct.GetClassNameFromInstIput(strFieldString);
	CString strFieldName = cInstruct.GetFieldNameFromInstIput(strFieldString);
	CString strFieldType = cInstruct.GetFieldTypeFromInstIput(strFieldString);

	cClassField.bStatic = bIsStatic;
	cClassField.strName = strFieldName;
	cClassField.strType = strFieldType;

	if (strFiledClassName == this->strClassName) {
		return true;
	}

	// 寻找这个Class是不是已经存在了
	for (unsigned int i = 0; i < this->listExternClassInfo.size(); i++) {
		if (this->listExternClassInfo[i].strClassName == strFiledClassName) {
			this->listExternClassInfo[i].listField.push_back(cClassField);

			// 去重
			sort(this->listExternClassInfo[i].listField.begin(), this->listExternClassInfo[i].listField.end());
			std::vector<CJavaExternClassField>::iterator iter = std::unique(this->listExternClassInfo[i].listField.begin(), this->listExternClassInfo[i].listField.end());
			this->listExternClassInfo[i].listField.erase(iter, this->listExternClassInfo[i].listField.end());
			return true;
		}
	}

	{
		CJavaExternClass cExternClass;
		cExternClass.strClassName = strFiledClassName;
		cExternClass.listField.clear();
		cExternClass.listMethod.clear();
		cExternClass.listField.push_back(cClassField);
		listExternClassInfo.push_back(cExternClass);
	}

	return true;
}

