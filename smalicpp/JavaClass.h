#pragma once

#include "JavaClass.h"
#include "JavaMethod.h"


class CJavaExternClassField {
public:
	CString strName;						// ����				ͨ��strName����
	CString strType;						// ����
	bool bStatic;							// ���ھ�̬����		���ھ�̬����

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
	CString strName;						// ����				ͨ��strName����
	CString strReturnType;					// ����
	std::vector<CString> listParam;
	CString strCallString;					// �����ַ���		�������Ϊ�ؼ��ֵ�
	CString strCppString;
	bool bStatic;							// ���ھ�̬����		���ھ�̬����

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


// ��Ҫ�ⲿ�����Class
class CJavaExternClass{
public:
	CString strClassName;
	CString strJvmClassName;

	// ����
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

	CString strClassName;										// ����
	CString strSuperName;										// ������
	std::vector<CString>		listStrImplements;				// �ӿ�����
	std::vector<CString>		listStrFields;					// ����
	std::vector<CJavaMethod>	listJavaMethods;				// �����б�

	std::vector<CString>		listExternClassList;			// �ⲿ�����Class�嵥

	std::vector<CString>		listPublicMemberList;			// ���г�Ա�嵥
	std::vector<CString>		listPrivateMemberList;			// ˽�����ͳ�Ա�嵥
	std::vector<CString>		listProtectMemberList;			// �������͵ĳ�Ա�嵥
	std::vector<CString>		listFieldInitCodeList;			// ��Ա������ʼ������

	// �ⲿ��Ҫӳ����ļ�����Щ����Ҫ����Dummy�ļ�������Ҫ������
	std::vector<CJavaExternClass> listExternClassInfo;			// �ⲿ�ļ���Ϣ

	// ����һ�����ú���
	bool InsertExternClassMethod(CString strCallMethodString, bool bIsStatic);
	bool InsertExternClassField(CString strFieldString, bool bIsStatic);

	// ���� smali �ļ�
	BOOL AnalyzeClassSmali(CString strSmaliFile);

	// ר�����ڴ��� Field �ķ��ŵĺ���
	std::vector<CString> GetFieldSymbolList(CString strLine);

	// ��Java�����ͣ�ת����Cpp������
	CString GetCppTypeFromJava(CString strType);

	CString strGetJvmClassNameFromCallMethodString(CString strCallMethodString);
	CString strGetJvmSignatureFromCallMethodString(CString strCallMethodString);


	BOOL OutputCppFile();
	BOOL OutputHeadFile();
	BOOL OutputJavaFile();
	BOOL OutputJniCppFile();
	BOOL OutputDependOnHeadFile();
};
