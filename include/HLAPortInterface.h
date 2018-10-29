#pragma once

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HLAPORTINTERFACE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HLAPORTINTERFACE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

/*
* Interface��
* @date : 2018/09/22
* @author : jihang
*/

#include "ObjectClassSet.h"
#include "InterfaceResponse.h"

using namespace std;

#ifdef HLAPORTINTERFACE_EXPORTS
#define HLAPORTINTERFACE_API __declspec(dllexport)
#else
#define HLAPORTINTERFACE_API __declspec(dllimport)
#endif

#define READY_TO_RUN "ReadyToRun"

// �����Ǵ� HLAPortInterface.dll ������
class HLAPORTINTERFACE_API CHLAPortInterface {
public:
	//����/����
public:
	CHLAPortInterface();
	virtual ~CHLAPortInterface() {};

public:
	//��ͣ״̬λ
	bool isPause;
	//����״̬λ
	bool isEnd;
	//�����ļ�
	string m_fedFile;
	//������
	string m_federationName;
	//�����Ա��
	string m_federateName;
	//�����ԱID
	long m_federateId;

	//�ӿڷ���
public:
	//��������
	InterfaceResponse<void>* createFederation();
	//����������������ԱID��ʧ�ܷ���-1��Ĭ�ϼ���fed�ļ��ж������������
	InterfaceResponse<long>* joinFederation();
	//�˳�����
	InterfaceResponse<void>* resignFederation();
	//�������Ĭ������fed�ļ��ж������������
	InterfaceResponse<void>* destroyFederation();
	//��ʼ�������Ŀǰ���޶����࣬����һ��
	InterfaceResponse<void>* initOneHandle(ObjectClassSet&);
	//ע������ͬ����
	InterfaceResponse<void>* registerSynchronization(string label);
	//���е�ͬ����
	InterfaceResponse<void>* synchronizationAchieved(string label);
	//����ʱ�����
	InterfaceResponse<void>* enableTimePolicy(double lookahead);
	//���������࣬Ŀǰ���޶����࣬����һ��
	InterfaceResponse<void>* publishOne(ObjectClassSet&);
	//���Ķ����࣬Ŀǰ���޶����࣬����һ��
	InterfaceResponse<void>* subscribeOne(ObjectClassSet&);
	//ע�������
	InterfaceResponse<long>* registerObject(string className);
	//���Ͷ����࣬Ŀǰ���޶�����
	InterfaceResponse<void>* sendObject(RTI::ObjectHandle, RTI::AttributeHandleValuePairSet*);
	//ʱ�䲽��
	InterfaceResponse<void>* advanceTime(double timestep);
	//ɾ�������࣬Ŀǰ���޶�����
	InterfaceResponse<void>* deleteOne(RTI::ObjectHandle);
	//ͨ��������λ������
	InterfaceResponse<long>* getObjectClass(RTI::ObjectHandle objectHandle);
	//��ȡ��ǰʱ��
	InterfaceResponse<double>* getCurrentTime();

	//=======================����Ϊ�ص�==========================
	//ͬ���ɹ�
	virtual void syncSuccess(const char *label) = 0;
	//ͬ��ʧ��
	virtual void syncFailure(const char *label) = 0;
	//����ͬ��
	virtual void announceSync(
		const char *label, const char *tag) = 0;
	//���ͬ��
	virtual void syncComplete(const char *label) = 0;
	//���ֶ���ʵ��
	virtual void discover(RTI::ObjectHandle theObject,
		RTI::ObjectClassHandle theObjectClass,
		const char * theObjectName) = 0;
	//���ն�����,Ŀǰ���޶�����
	virtual void processData(RTI::ObjectHandle,
		const RTI::AttributeHandleValuePairSet&, const char*) = 0;
	//ɾ������ʵ��
	virtual void remove(RTI::ObjectHandle theObject, const char *theTag) = 0;
};