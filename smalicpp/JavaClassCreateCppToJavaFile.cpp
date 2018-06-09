#include "stdafx.h"
#include "JavaClass.h"
#include "JavaMethod.h"


//jclass ClassCJM = (*env)->FindClass(env, "com/example/cjm/CJM");
//jmethodID MethodDisplayMessage = (*env)->GetMethodID(env, ClassCJM, "displayMessage", "(Ljava/lang/String;)V");
//jstring value = (*env)->NewStringUTF(env, "Hello World!");
//(*env)->CallVoidMethod(env, thiz, MethodDisplayMessage, value);

//jmethodID method4 = (*env)->GetStaticMethodID(env, dpclazz, "printStaticStr", "(Ljava/lang/String;)V");
//(*env)->CallStaticVoidMethod(env, dpclazz, method4, (*env)->NewStringUTF(env, "static haha in c"));

//这是完整的可调用的函数列表
//jobject(*CallObjectMethod)(JNIEnv*, jobject, jmethodID, ...);
//jobject(*CallObjectMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jobject(*CallObjectMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jboolean(*CallBooleanMethod)(JNIEnv*, jobject, jmethodID, ...);
//jboolean(*CallBooleanMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jboolean(*CallBooleanMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jbyte(*CallByteMethod)(JNIEnv*, jobject, jmethodID, ...);
//jbyte(*CallByteMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jbyte(*CallByteMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jchar(*CallCharMethod)(JNIEnv*, jobject, jmethodID, ...);
//jchar(*CallCharMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jchar(*CallCharMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jshort(*CallShortMethod)(JNIEnv*, jobject, jmethodID, ...);
//jshort(*CallShortMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jshort(*CallShortMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jint(*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
//jint(*CallIntMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jint(*CallIntMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jlong(*CallLongMethod)(JNIEnv*, jobject, jmethodID, ...);
//jlong(*CallLongMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jlong(*CallLongMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jfloat(*CallFloatMethod)(JNIEnv*, jobject, jmethodID, ...) __NDK_FPABI__;
//jfloat(*CallFloatMethodV)(JNIEnv*, jobject, jmethodID, va_list) __NDK_FPABI__;
//jfloat(*CallFloatMethodA)(JNIEnv*, jobject, jmethodID, jvalue*) __NDK_FPABI__;
//jdouble(*CallDoubleMethod)(JNIEnv*, jobject, jmethodID, ...) __NDK_FPABI__;
//jdouble(*CallDoubleMethodV)(JNIEnv*, jobject, jmethodID, va_list) __NDK_FPABI__;
//jdouble(*CallDoubleMethodA)(JNIEnv*, jobject, jmethodID, jvalue*) __NDK_FPABI__;
//void(*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
//void(*CallVoidMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//void(*CallVoidMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);



//jobject(*CallNonvirtualObjectMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jobject(*CallNonvirtualObjectMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jobject(*CallNonvirtualObjectMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jboolean(*CallNonvirtualBooleanMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jboolean(*CallNonvirtualBooleanMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jboolean(*CallNonvirtualBooleanMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jbyte(*CallNonvirtualByteMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jbyte(*CallNonvirtualByteMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jbyte(*CallNonvirtualByteMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jchar(*CallNonvirtualCharMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jchar(*CallNonvirtualCharMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jchar(*CallNonvirtualCharMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jshort(*CallNonvirtualShortMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jshort(*CallNonvirtualShortMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jshort(*CallNonvirtualShortMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jint(*CallNonvirtualIntMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jint(*CallNonvirtualIntMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jint(*CallNonvirtualIntMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jlong(*CallNonvirtualLongMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jlong(*CallNonvirtualLongMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jlong(*CallNonvirtualLongMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jfloat(*CallNonvirtualFloatMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jfloat(*CallNonvirtualFloatMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jfloat(*CallNonvirtualFloatMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//jdouble(*CallNonvirtualDoubleMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//jdouble(*CallNonvirtualDoubleMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//jdouble(*CallNonvirtualDoubleMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);
//void(*CallNonvirtualVoidMethod)(JNIEnv*, jobject, jclass,	jmethodID, ...);
//void(*CallNonvirtualVoidMethodV)(JNIEnv*, jobject, jclass,	jmethodID, va_list);
//void(*CallNonvirtualVoidMethodA)(JNIEnv*, jobject, jclass,	jmethodID, jvalue*);


//jobject jobjMyObj = jenv->NewObject(jclzMyObject, jmethodConstructID);
//jfieldID nameField = jenv->GetFieldID(jclzMyObject, "name", "Ljava/lang/String;");
//jfieldID numberField = jenv->GetFieldID(jclzMyObject, , "number", "I");
//jenv->SetObjectField(jobjMyObj, nameField, myObjects[i].name);
//jenv->SetIntField(jobjMyObj, numberField, myObjects[i].number);
//jenv->SetObjectArrayElement(array, i, jobjMyObj);
//jenv->DeleteLocalRef(jobjMyObj);

//typedef _jobject*       jobject;
//typedef _jclass*        jclass;
//typedef _jstring*       jstring;
//typedef _jarray*        jarray;
//typedef _jobjectArray*  jobjectArray;
//typedef _jbooleanArray* jbooleanArray;
//typedef _jbyteArray*    jbyteArray;
//typedef _jcharArray*    jcharArray;
//typedef _jshortArray*   jshortArray;
//typedef _jintArray*     jintArray;
//typedef _jlongArray*    jlongArray;
//typedef _jfloatArray*   jfloatArray;
//typedef _jdoubleArray*  jdoubleArray;
//typedef _jthrowable*    jthrowable;
//typedef _jobject*       jweak;
//jboolean    z;
//jbyte       b;
//jchar       c;
//jshort      s;
//jint        i;
//jlong       j;
//jfloat      f;
//jdouble     d;
//jobject     l;


// 生成上面依赖的头文件
BOOL CJavaClass::OutputDependOnHeadFile() {

	printf("-->生成Dummy头文件\n");

	for (unsigned int i = 0; i < listExternClassInfo.size(); i++) {


		// 创建Class头
		printf("#ifndef %s_h__\n", listExternClassInfo[i].strClassName);
		printf("#define %s_h__\n", listExternClassInfo[i].strClassName);
		printf("class %s {\npublic:\n", listExternClassInfo[i].strClassName);

		//printf("Extern Class %s\n", listExternClassInfo[i].strClassName);

		// 定义标准定义变量
		printf("\tjclass jvmClass;\n");

		// 引入变量
		for (unsigned int j = 0; j < listExternClassInfo[i].listField.size(); j++) {
			printf("\t%s %s %s\n", listExternClassInfo[i].listField[j].bStatic ? "static" : "", listExternClassInfo[i].listField[j].strType, listExternClassInfo[i].listField[j].strName);
		}

		// 创建构造函数
		int nFindConstructionMethod = -1;
		for (unsigned int j = 0; j < listExternClassInfo[i].listMethod.size(); j++) {
			if (listExternClassInfo[i].listMethod[j].strName == CString("<init>")) {
				nFindConstructionMethod = j;
				break;
			}
		}
		// 没有找到构造函数，生成默认的构造函数
		if (nFindConstructionMethod < 0) {
			// 生成函数头
			printf("\t%s(){\n", listExternClassInfo[i].strClassName);
			// 寻找默认函数

			CString strJvmClassName = listExternClassInfo[i].strJvmClassName;
			CString strJvmSignature = CString("()V");
			CString strMethodName = CString("<init>");

			printf("\t\tjvmClass = (*env)->FindClass(env,\"%s\");\n", strJvmClassName);
			printf("\t\tif( jvmClass != NULL ) {\n");
			{
				printf("\t\t\tjmethodID jvmMethod = (*env)->GetMethodID(env, jvmClass, \"%s\", \"%s\");\n", strMethodName, strJvmSignature);
				printf("\t\t\tif( jvmMethod != NULL ) {\n");
				{
					printf("\t\t\t\t(*env)->CallVoidMethod(env, jvmClass, jvmMethod);\n");
				}
				printf("\t\t\t}\n");
			}
			printf("\t\t}\n");

			// 生成函数尾巴
			printf("\t%};\n");
		}

		// 生成析构函数
		{
			printf("\t~%s(){\n", listExternClassInfo[i].strClassName);
			// 寻找默认函数

			CString strJvmClassName = listExternClassInfo[i].strJvmClassName;

			// 生成函数尾巴
			printf("\t%};\n");
		}



		for (unsigned int j = 0; j < listExternClassInfo[i].listMethod.size(); j++) {
			//printf("%s\n", listExternClassInfo[i].listMethod[j].strCppString);

			CString strJvmClassName = strGetJvmClassNameFromCallMethodString(listExternClassInfo[i].listMethod[j].strCallString);
			CString strJvmSignature = strGetJvmSignatureFromCallMethodString(listExternClassInfo[i].listMethod[j].strCallString);
			CString strMethodName = listExternClassInfo[i].listMethod[j].strName;

			if (strMethodName == CString("<init>")) {
				strMethodName = listExternClassInfo[i].strClassName;
			}

			// 生成函数头
			printf("\t%s{\n", listExternClassInfo[i].listMethod[j].strCppString);

			if (listExternClassInfo[i].listMethod[j].strReturnType == CString("void")) {

				//1. 这里生成的Class要和Java里面完整对应， 
				//		例如构造函数要调用Java里面的<init>函数
				//		析构函数需要调用Java里面的对象释放函数，
				//2. 如果是自己的C++类要传递参数过去，需要重新封装成Jvm的对象传递上去
				//3. 如果是已经实现的对象，这个要走一个流程，如果是自己没有实现的类，那么这个类肯定只是引用，只需要保存一个系统传递下来的对象


				// 找到虚拟机和函数
				printf("\t\tjvmClass = (*env)->FindClass(env,\"%s\");\n", strJvmClassName);
				printf("\t\tif( jvmClass != NULL ) {\n");
				{
					printf("\t\t\tjmethodID jvmMethod = (*env)->GetMethodID(env, jvmClass, \"%s\", \"%s\");\n", strMethodName, strJvmSignature);
					printf("\t\t\tif( jvmMethod != NULL ) {\n");
					{
						printf("\t\t\t\t(*env)->CallVoidMethod(env, jvmClass, jvmMethod);\n");
					}
					printf("\t\t\t}\n");
				}
				printf("\t\t}\n");
			}

			// 生成函数尾
			printf("\t};\n");

		}
		// Class 尾巴
		printf("};\n");
		printf("#endif\n");
	}

	return true;
}
