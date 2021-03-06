#pragma once

#include "JavaClass.h"
#include "JavaMethod.h"


class CJavaExternClassField {
public:
	CString strName;						// 名字				通过strName排序
	CString strType;						// 类型
	bool bStatic;							// 属于静态函数		属于静态函数

	CJavaExternClassField() {
		strName.Empty();
		strType.Empty();
		bStatic = false;
	}
	~CJavaExternClassField() {
	}

	CJavaExternClassField(const CJavaExternClassField & _c) {
		this->strName = _c.strName;
		this->strType = _c.strType;
		this->bStatic = _c.bStatic;
	};

	CJavaExternClassField & operator = (const CJavaExternClassField & _c) {
		this->strName = _c.strName;
		this->strType = _c.strType;
		this->bStatic = _c.bStatic;
		return *this;
	};

	bool operator == (const CJavaExternClassField & p) {
		CString strQ = this->strName;
		CString strP = p.strName;


		if (strQ.Compare(strP) == 0) {
			return true;
		}

		return false;
	};

	bool operator < (const CJavaExternClassField & p) {
		CString strQ = this->strName;
		CString strP = p.strName;

		if (strQ.Compare(strP) < 0) {
			return true;
		}

		return false;
	};

};

class CJavaExternClassMethod {
public:
	CString strName;						// 名字				通过strName排序
	CString strReturnType;					// 类型
	std::vector<CString> listParam;
	CString strCallString;					// 调用字符串		这个是最为关键字的
	CString strCppString;
	bool bStatic;							// 属于静态函数		属于静态函数

	CJavaExternClassMethod() {
		strName.Empty();
		strReturnType.Empty();
		listParam.clear();
		strCallString.Empty();
		strCppString.Empty();
		bStatic = false;
	}
	~CJavaExternClassMethod() {
	}

	CJavaExternClassMethod(const CJavaExternClassMethod & _c) {
		this->strName = _c.strName;
		this->strReturnType = _c.strReturnType;
		this->listParam = _c.listParam;
		this->strCallString = _c.strCallString;
		this->strCppString = _c.strCppString;
		this->bStatic = _c.bStatic;
	};

	CJavaExternClassMethod & operator = (const CJavaExternClassMethod & _c) {
		this->strName = _c.strName;
		this->strReturnType = _c.strReturnType;
		this->listParam = _c.listParam;
		this->strCallString = _c.strCallString;
		this->strCppString = _c.strCppString;
		this->bStatic = _c.bStatic;
		return *this;
	};

	bool operator == (const CJavaExternClassMethod & p) {
		CString strQ = this->strCallString;
		CString strP = p.strCallString;


		if (strQ.Compare(strP) == 0) {
			return true;
		}

		return false;
	};

	bool operator < (const CJavaExternClassMethod & p) {
		CString strQ = this->strCallString;
		CString strP = p.strCallString;

		if (strQ.Compare(strP) < 0) {
			return true;
		}

		return false;
	};

};


// 需要外部引入的Class
class CJavaExternClass{
public:
	CString strClassName;
	CString strJvmClassName;

	// 变量
	std::vector<CJavaExternClassField> listField;
	std::vector<CJavaExternClassMethod> listMethod;

	CJavaExternClass(){
		strClassName.Empty();
		strJvmClassName.Empty();
		listField.clear();
		listMethod.clear();
	};
	~CJavaExternClass(){};


	CJavaExternClass(const CJavaExternClass & _c) {
		this->strClassName = _c.strClassName;
		this->strJvmClassName = _c.strJvmClassName;
		this->listField = _c.listField;
		this->listMethod = _c.listMethod;
	};

	CJavaExternClass & operator = (const CJavaExternClass & _c) {
		this->strClassName = _c.strClassName;
		this->strJvmClassName = _c.strJvmClassName;
		this->listField = _c.listField;
		this->listMethod = _c.listMethod;
		return *this;
	};
};


class CJavaClass
{
public:

	enum {
		ACC_PUBLIC = 0x00000001,       // class, field, method, ic
		ACC_PRIVATE = 0x00000002,       // field, method, ic
		ACC_PROTECTED = 0x00000004,       // field, method, ic
		ACC_STATIC = 0x00000008,       // field, method, ic
		ACC_FINAL = 0x00000010,       // class, field, method, ic
		ACC_SYNCHRONIZED = 0x00000020,       // method (only allowed on natives)
		ACC_SUPER = 0x00000020,       // class (not used in Dalvik)
		ACC_VOLATILE = 0x00000040,       // field
		ACC_BRIDGE = 0x00000040,       // method (1.5)
		ACC_TRANSIENT = 0x00000080,       // field
		ACC_VARARGS = 0x00000080,       // method (1.5)
		ACC_NATIVE = 0x00000100,       // method
		ACC_INTERFACE = 0x00000200,       // class, ic
		ACC_ABSTRACT = 0x00000400,       // class, method, ic
		ACC_STRICT = 0x00000800,       // method
		ACC_SYNTHETIC = 0x00001000,       // field, method, ic
		ACC_ANNOTATION = 0x00002000,       // class, ic (1.5)
		ACC_ENUM = 0x00004000,       // class, field, ic (1.5)
		ACC_CONSTRUCTOR = 0x00010000,       // method (Dalvik only)
		ACC_DECLARED_SYNCHRONIZED =
		0x00020000,       // method (Dalvik only)
		ACC_CLASS_MASK =
		(ACC_PUBLIC | ACC_FINAL | ACC_INTERFACE | ACC_ABSTRACT
		| ACC_SYNTHETIC | ACC_ANNOTATION | ACC_ENUM),
		ACC_INNER_CLASS_MASK =
		(ACC_CLASS_MASK | ACC_PRIVATE | ACC_PROTECTED | ACC_STATIC),
		ACC_FIELD_MASK =
		(ACC_PUBLIC | ACC_PRIVATE | ACC_PROTECTED | ACC_STATIC | ACC_FINAL
		| ACC_VOLATILE | ACC_TRANSIENT | ACC_SYNTHETIC | ACC_ENUM),
		ACC_METHOD_MASK =
		(ACC_PUBLIC | ACC_PRIVATE | ACC_PROTECTED | ACC_STATIC | ACC_FINAL
		| ACC_SYNCHRONIZED | ACC_BRIDGE | ACC_VARARGS | ACC_NATIVE
		| ACC_ABSTRACT | ACC_STRICT | ACC_SYNTHETIC | ACC_CONSTRUCTOR
		| ACC_DECLARED_SYNCHRONIZED),
	};

	CJavaClass();
	~CJavaClass();

	CString strClassName;										// 类名
	CString strSuperName;										// 父类名
	std::vector<CString>		listStrImplements;				// 接口类型
	std::vector<CString>		listStrFields;					// 变量
	std::vector<CJavaMethod>	listJavaMethods;				// 方法列表

	std::vector<CString>		listExternClassList;			// 外部引入的Class清单

	std::vector<CString>		listPublicMemberList;			// 公有成员清单
	std::vector<CString>		listPrivateMemberList;			// 私有类型成员清单
	std::vector<CString>		listProtectMemberList;			// 保护类型的成员清单
	std::vector<CString>		listFieldInitCodeList;			// 成员变量初始化类型

	// 外部需要映入的文件，这些都需要生成Dummy文件的所以要很正规
	std::vector<CJavaExternClass> listExternClassInfo;			// 外部文件信息

	// 插入一个调用函数
	bool InsertExternClassMethod(CString strCallMethodString, bool bIsStatic);
	bool InsertExternClassField(CString strFieldString, bool bIsStatic);

	// 处理 smali 文件
	BOOL AnalyzeClassSmali(CString strSmaliFile);

	// 专门用于处理 Field 的符号的函数
	std::vector<CString> GetFieldSymbolList(CString strLine);

	// 将Java的类型，转换成Cpp的类型
	CString GetCppTypeFromJava(CString strType);

	CString strGetJvmClassNameFromCallMethodString(CString strCallMethodString);
	CString strGetJvmSignatureFromCallMethodString(CString strCallMethodString);


	BOOL OutputCppFile();
	BOOL OutputHeadFile();
	BOOL OutputJavaFile();
	BOOL OutputJniCppFile();
	BOOL OutputDependOnHeadFile();
};
