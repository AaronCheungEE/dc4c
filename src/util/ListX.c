/*
** ����		:	ListX
** ������	:	��������list�����ĺ�����
** ����		:	calvin
** E-mail	:	
** QQ		:	
** ��������ʱ��	:	2003/10/18
** ��������ʱ��	:	2005/5/2
*/

#include "ListX.h"

/*
** ������		:	CreateList
** ��������		:	����һ�����͵�����list
** �������˵��	:	��
** ����ֵ		:	���� NULL
** ������־		:	2003/10/18	����
*/

SList *CreateList()
{
	return NULL;
}

/*
** ������		:	DestroyList
** ��������		:	����һ�����͵�����list
** �������˵��	:	SList **list				������׵�ַ
**					void (* DeleteNodeMember)()	ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL DestroyList( SList **list , BOOL (* DeleteNodeMember)( void *pv ) )
{
	if( (*list) == NULL )
		return TRUE;
	
	if( DeleteAllListNode( list , DeleteNodeMember ) == FALSE )
		return FALSE;

	return TRUE;
}

/*
** ������		:	AddListNode
** ��������		:	���һ����㵽�����ĩβ
** �������˵��	:	SList **list							������׵�ַ
**					void *member							��������Ա
**					long msize								����Ա�Ĵ�С
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

SListNode *AddListNode( SList **list , void *member , long msize , BOOL (* FreeNodeMember)( void *pv ) )
{
	SListNode *node,*nodeNew;

	if( *list == NULL )
	{
		nodeNew=(SListNode *)malloc( sizeof(SListNode) );
		if( nodeNew == NULL )
			return NULL;

		nodeNew->member			= member ;
		nodeNew->msize			= msize ;
		nodeNew->FreeNodeMember	= FreeNodeMember ;

		nodeNew->prev = NULL ;
		nodeNew->next = NULL ;

		*list = nodeNew ;

		return nodeNew;
	}
	else
	{
		node = *list ;
		while( node->next != NULL )
			node = node->next ;

		nodeNew=(SListNode *)malloc( sizeof( SListNode ) );
		if( nodeNew == NULL )
			return NULL;

		nodeNew->member			= member ;
		nodeNew->msize			= msize ;
		nodeNew->FreeNodeMember	= FreeNodeMember ;

		nodeNew->prev = node;
		nodeNew->next = NULL;

		node->next = nodeNew;

		return nodeNew;
	}
}

/*
** ������		:	InsertListNodeBefore
** ��������		:	����һ����㵽��ǰ������ǰ
** �������˵��	:	SList **list							������ָ��
**					SList **nodeList						��ǰ������
**					void *member							��������Ա
**					long msize								����Ա�Ĵ�С
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

SListNode *InsertListNodeBefore( SList **list , SListNode **nodeList , void *member , long msize , BOOL (* FreeNodeMember)( void *pv ) )
{
	SListNode *nodeNew=NULL;
	
	if( (*list) == NULL )
	{
		nodeNew = AddListNode( list , member , msize , FreeNodeMember ) ;
		if( nodeNew == NULL )
			return NULL;
		
		(*nodeList) = (*list) ;
		
		return nodeNew;
	}
	else
	{
		if( (*nodeList) == NULL )
			(*nodeList) = (*list) ;
	}
	
	nodeNew=(SListNode *)malloc( sizeof( SListNode ) );
	if( nodeNew == NULL )
		return NULL;

	nodeNew->member			= member ;
	nodeNew->msize			= msize ;
	nodeNew->FreeNodeMember	= FreeNodeMember ;
	
	if( (*nodeList)->prev == NULL )
	{
		nodeNew->prev = NULL ;
		
		nodeNew->next = (*nodeList) ;
		(*nodeList)->prev = nodeNew ;
		
		(*list) = nodeNew ;
		(*nodeList) = nodeNew ;
	}
	else
	{
		(*nodeList)->prev->next = nodeNew ;
		nodeNew->prev = (*nodeList)->prev ;
		
		nodeNew->next = (*nodeList) ;
		(*nodeList)->prev = nodeNew ;
		
		(*nodeList) = nodeNew ;
	}
	
	return nodeNew;
}

/*
** ������		:	InsertListNodeAfter
** ��������		:	����һ����㵽��ǰ�������
** �������˵��	:	SList **list							������ָ��
**					SList **nodeList						��ǰ������
**					void *member							��������Ա
**					long msize								����Ա�Ĵ�С
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

SListNode *InsertListNodeAfter( SList **list , SListNode **nodeList , void *member , long msize , BOOL (* FreeNodeMember)( void *pv ) )
{
	SListNode *nodeNew=NULL;
	
	if( (*list) == NULL )
	{
		nodeNew = AddListNode( list , member , msize , FreeNodeMember ) ;
		if( nodeNew == NULL )
			return NULL;
		
		(*nodeList) = (*list) ;
		
		return nodeNew;
	}
	else
	{
		if( (*nodeList) == NULL )
			(*nodeList) = (*list) ;
	}
	
	nodeNew=(SListNode *)malloc( sizeof( SListNode ) );
	if( nodeNew == NULL )
		return NULL;

	nodeNew->member			= member ;
	nodeNew->msize			= msize ;
	nodeNew->FreeNodeMember	= FreeNodeMember ;

	if( (*nodeList)->next == NULL )
	{
		nodeNew->next = NULL ;
	}
	else
	{
		(*nodeList)->next->prev = nodeNew ;
		nodeNew->next = (*nodeList)->next ;
	}
	
	nodeNew->prev = (*nodeList) ;
	(*nodeList)->next = nodeNew ;

	(*nodeList) = nodeNew ;

	return nodeNew;
}

/*
** ������		:	InsertListIndexNode
** ��������		:	����һ����㵽����ĵ�index�����ǰ
** �������˵��	:	SList **list							������׵�ַ
**					int index								����ĵ�index�����
**					void *member							��������Ա
**					long msize								����Ա�Ĵ�С
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

SListNode *InsertListIndexNode( SList **list , int index , void *member , long msize , BOOL (* FreeNodeMember)( void *pv ) )
{
	SListNode *node=NULL;

	if( ( *list ) == NULL )
		return AddListNode( list , member , msize , FreeNodeMember );

	node = GetListIndexNode( ( *list ) , index ) ;

	if( node == NULL )
		return NULL;

	if( InsertListNode( list , &node , member , msize , FreeNodeMember ) == NULL )
		return NULL;

	if( index == 1 )
		( *list ) = ( *list )->prev;

	return node;
}

/*
** ������		:	DeleteListNode
** ��������		:	ɾ����ǰ���
** �������˵��	:	SListHead **list						�����׽��
**					SListNode **node						����ǰ���
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
**					2004/3/3	�޸� ������ǰ������׽��ʱ����ɾ����һ����㣬��ʧ�ڶ�������BUG
*/

BOOL DeleteListNode( SList **list , SListNode **node , BOOL (* FreeNodeMember)( void *pv ) )
{
	SListNode *nodeDelete = NULL ;
	
	if( (*list) == NULL )
		return FALSE;
	
	if( (*node) == NULL )
		return FALSE;
	
	if( (*node)->prev == NULL )
	{
		if( (*node)->next == NULL ) /* ֻ��һ����� */
		{
			nodeDelete = (*node) ;
			
			if( FreeNodeMember != NULL )
			{
				FreeNodeMember( nodeDelete->member );
			}
			else if( nodeDelete->FreeNodeMember != NULL )
			{
				nodeDelete->FreeNodeMember( nodeDelete->member );
			}
			
			free( nodeDelete );
			(*list) = NULL ;
			(*node) = NULL ;
		}
		else /* if( (*nodeList)->next != NULL ) */ /* ��һ����� */
		{
			nodeDelete = (*node) ;
			
			if( (*list) == (*node) )
			{
				(*node) = (*node)->next ;
				(*node)->prev = NULL ;
				
				if( FreeNodeMember != NULL )
				{
					FreeNodeMember( nodeDelete->member );
				}
				else if( nodeDelete->FreeNodeMember != NULL )
				{
					nodeDelete->FreeNodeMember( nodeDelete->member );
				}
				
				free( nodeDelete );
				(*list) = (*node) ;
			}
			else
			{
				(*node) = (*node)->next ;
				(*node)->prev = NULL ;
				
				if( FreeNodeMember != NULL )
					FreeNodeMember( nodeDelete->member );
				else if( nodeDelete->FreeNodeMember != NULL )
					nodeDelete->FreeNodeMember( nodeDelete->member );
				
				free( nodeDelete );
			}
		}
	}
	else /* if( (*nodeList)->prev != NULL ) */
	{
		if( (*node)->next == NULL ) /* ���һ����� */
		{
			nodeDelete = (*node) ;
	
			(*node) = (*node)->prev ;
			(*node)->next = NULL ;
			
			if( FreeNodeMember != NULL )
				FreeNodeMember( nodeDelete->member );
			else if( nodeDelete->FreeNodeMember != NULL )
				nodeDelete->FreeNodeMember( nodeDelete->member );
			
			free( nodeDelete );
		}
		else /* if( (*nodeList)->next != NULL ) */ /* �м�Ľ�� */
		{
			nodeDelete = (*node) ;
			
			(*node)->prev->next = (*node)->next ;
			(*node)->next->prev = (*node)->prev ;
			
			(*node) = (*node)->next ;
			
			if( FreeNodeMember != NULL )
				FreeNodeMember( nodeDelete->member );
			else if( nodeDelete->FreeNodeMember != NULL )
				nodeDelete->FreeNodeMember( nodeDelete->member );
			
			free( nodeDelete );
		}
	}
	
	return TRUE;
}

/*
** ������		:	DeleteListIndexNode
** ��������		:	ɾ������ĵ�index�����
** �������˵��	:	SList **list							�����׽��
**					int index								��index�����
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL DeleteListIndexNode( SListNode **list , int index , BOOL (* FreeNodeMember)( void *pv ) )
{
	SListNode *node = NULL ;

	if( (*list) == NULL )
		return FALSE;
	
	node = GetListIndexNode( (*list) , index );
	if( node == NULL )
		return FALSE;

	return DeleteListNode( list , &node , FreeNodeMember );
}

/*
** ������		:	DeleteAllListNode
** ��������		:	ɾ���������н��
** �������˵��	:	SList **list							�����׽��
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL DeleteAllListNode( SList **list , BOOL (* FreeNodeMember)( void *pv ) )
{
	if( (*list) == NULL )
		return TRUE;
	
	while( DeleteListNode( list , list , FreeNodeMember ) == TRUE );
	
	(*list) = NULL ;
	
	return TRUE;
}

/*
** ������		:	FindFirstListNode
** ��������		:	��λ����ĵ�һ�����
** �������˵��	:	SList *list			�����׽��
** ����ֵ		:	�ɹ������� ��һ������ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

SListNode *FindFirstListNode( SList *list )
{
	return list;
}

/*
** ������		:	FindLastListNode
** ��������		:	��λ����ĵ�һ�����
** �������˵��	:	SList *list			�����׽��
** ����ֵ		:	�ɹ������� ��һ������ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

SListNode *FindLastListNode( SList *list )
{
	SListNode *node=NULL;
	
	node = FindFirstListNode( list ) ;
	while( FindNextListNode( node ) != NULL )
		node = FindNextListNode( node ) ;
	
	return node;
}

/*
** ������		:	FindPrevListNode
** ��������		:	��λ�������һ�����
** �������˵��	:	SListNode *nodeList			��ǰ������
** ����ֵ		:	�ɹ������� ��һ������ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

SListNode *FindPrevListNode( SListNode *nodeList )
{
	if( nodeList == NULL )
		return NULL;
		
	if( nodeList->prev == NULL )
		return NULL;
		
	return nodeList->prev;
}

/*
** ������		:	FindPrevListNode
** ��������		:	��λ�������һ�����
** �������˵��	:	SListNode *nodeList			��ǰ������
** ����ֵ		:	�ɹ������� ��һ������ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

SListNode *FindNextListNode( SListNode *nodeList )
{
	if( nodeList == NULL )
		return NULL;
		
	return nodeList->next;
}

/*
** ������		:	IsFirstListNode
** ��������		:	�ж��Ƿ�������ĵ�һ�����
** �������˵��	:	SListNode *nodeList			��ǰ������
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL IsFirstListNode( SListNode *nodeList )
{
	if( nodeList->prev == NULL )
		return TRUE;
	else
		return FALSE;
}

/*
** ������		:	IsFirstListNode
** ��������		:	�ж��Ƿ�����������һ�����
** �������˵��	:	SListNode *nodeList			��ǰ������
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL IsLastListNode( SListNode *nodeList )
{
	if( nodeList->next == NULL )
		return TRUE;
	else
		return FALSE;
}

/*
** ������		:	IsListEmpty
** ��������		:	�ж��Ƿ��ǿ�����
** �������˵��	:	SList *list			�����׽��
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2004/2/18	����
*/

BOOL IsListEmpty( SList *list )
{
	if( list == NULL )
		return TRUE;
	else
		return FALSE;
}

/*
** ������		:	IsListNodeValid
** ��������		:	�жϵ�ǰ����Ƿ���Ч
** �������˵��	:	SList *list			�����׽��
** ����ֵ		:	��Ч������ TRUE
**					��Ч������ FALSE
** ������־		:	2004/2/18	����
*/

BOOL IsListNodeValid( SListNode *node )
{
	if( node == NULL )
		return FALSE;
	else
		return TRUE;
}

/*
** ������		:	GetListIndexNode
** ��������		:	�õ���position��������
** �������˵��	:	SList *list			�����׽��
**					long position		λ�ã���1��ʼ��
** ����ֵ		:	�ɹ������� ����ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

SListNode *GetListIndexNode( SList *list , long position )
{
	SListNode *node;
	long i=0;

	if(position<1)
		return NULL;

	if( position == 1 )
		return list;
	
	position--;
	
	node = list ;
	for( i=0 ; i<position ; i++ )
	{
		if( node == NULL )
			return NULL;

		node = node->next ;
	}

	return node;
}

/*
** ������		:	GetListIndexNode
** ��������		:	�õ���position���������Ա
** �������˵��	:	SList *list			�����׽��
**					long position		λ�ã���1��ʼ��
** ����ֵ		:	�ɹ������� ����Ա��ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

void *GetListIndexMember( SList *list , long position )
{
	SListNode *node = NULL ;

	node = GetListIndexNode( list , position );

	if( node == NULL )
		return NULL;
	else
		return GetNodeMember( node );
}

/*
** ������		:	GetNodeMember
** ��������		:	�õ���ǰ���ĳ�Ա
** �������˵��	:	SListNode *nodeList		��ǰ������
** ����ֵ		:	�ɹ������� ����Ա��ַ
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

void *GetNodeMember( SListNode *nodeList )
{
	if( nodeList == NULL )
		return NULL;
	else
		return nodeList->member;
}

/*
** ������		:	CountListNodes
** ��������		:	�õ�����������
** �������˵��	:	SList *list			�����׽��
** ����ֵ		:	�ɹ������� �������
**					ʧ�ܣ����� NULL
** ������־		:	2003/10/18	����
*/

long CountListNodes( SList *list )
{
	int count;
	SListNode *node=NULL;
		
	if( list == NULL )
		return 0;
	
	count = 0 ;
	node = list ;
	while( node != NULL )
	{
		count++;
		
		node = node->next ;
	}
	
	return count;
}

long AccessList( SList *listHead , BOOL (* AccessListNodeProc)( void *member ) )
{
	SListNode *node=NULL;
	BOOL bReturnValue;
	long lIndex;
	
	if( listHead == NULL )
		return -1;
	
	node = listHead ;
	lIndex = 1 ;
	while( node != NULL )
	{
		bReturnValue = AccessListNodeProc( node->member ) ;
		if( bReturnValue != TRUE )
			return lIndex;
		
		node = node->next ;
		lIndex++;
	}
	
	return -1;
}

int SwapTwoListNodes( SListNode *pnode1 , SListNode *pnode2 )
{
	SListNode nodeBackup ;
	
	if( pnode1 == NULL || pnode2 == NULL )
		return -1;
	
	nodeBackup.msize		= pnode1->msize ;
	nodeBackup.member		= pnode1->member ;
	nodeBackup.FreeNodeMember	= pnode1->FreeNodeMember ;
	
	pnode1->msize			= pnode2->msize ;
	pnode1->member			= pnode2->member ;
	pnode1->FreeNodeMember		= pnode2->FreeNodeMember ;
	
	pnode2->msize			= nodeBackup.msize ;
	pnode2->member			= nodeBackup.member ;
	pnode2->FreeNodeMember		= nodeBackup.FreeNodeMember ;
	
	return 0;
}

int SortList( SList *plist , int (* SortListNodeProc)( void *pmember1 , void *pmember2 ) )
{
	SListNode *pnode1 = NULL ;
	SListNode *pnode2 = NULL ;
	SListNode *pnodeSelected = NULL ;
	int iret ;
	
	if( plist == NULL )
		return -1;
	
	pnode1 = plist ;
	while( pnode1->next != NULL )
	{
		pnodeSelected = pnode1 ;
		pnode2 = pnode1 ;
		while( pnode2 != NULL )
		{
			iret = SortListNodeProc( pnodeSelected->member , pnode2->member ) ;
			if( iret > 0 )
				pnodeSelected = pnode2 ;
			
			pnode2 = pnode2->next ;
		}
		if( pnode1 != pnodeSelected )
		{
			iret = SwapTwoListNodes( pnode1 , pnodeSelected ) ;
			if( iret < 0 )
				return -2;
		}
		
		pnode1 = pnode1->next ;
	}
	
	return 0;
}

BOOL CopyList( SList **pplistSource , SList **pplistDest , BOOL (* CopyListNodeProc)( void *pmemberCopyFrom , long *plmsize , void **ppmemberNew ) )
{
	SListNode *pnode = NULL ;
	void *pmember = NULL ;
	long lmsize ;
	SListNode *pnodeCopy = NULL ;
	BOOL bret ;
	
	pnode = (*pplistSource) ;
	while( pnode != NULL )
	{
		if( CopyListNodeProc == NULL )
		{
			pmember = malloc( pnode->msize ) ;
			if( pmember == NULL )
				return FALSE;
			
			memcpy( pmember , pnode->member , pnode->msize );
		}
		else
		{
			lmsize = pnode->msize ;
			bret = CopyListNodeProc( pnode->member , &lmsize , &pmember ) ;
			if( bret != TRUE )
				return FALSE;
		}
		
		pnodeCopy = AddListNode( pplistDest , pmember , lmsize , pnode->FreeNodeMember ) ;
		if( pnodeCopy == NULL )
		{
			if( CopyListNodeProc == NULL )
			{
				free( pmember );
			}
			else
			{
				pnode->FreeNodeMember( pmember );
			}
			
			return FALSE;
		}
		
		pnode = pnode->next ;
	}
	
	return TRUE;
}

BOOL JoinList( SList **pplistSource , SList **pplistAddition )
{
	if( pplistSource == NULL || pplistAddition == NULL )
	{
		return FALSE;
	}
	
	if( (*pplistSource) == NULL && (*pplistAddition) == NULL )
	{
		return TRUE;
	}
	else if( (*pplistSource) == NULL )
	{
		(*pplistSource) = (*pplistAddition) ;
		
		return TRUE;
	}
	else if( (*pplistAddition) == NULL )
	{
		return TRUE;
	}
	else
	{
		SListNode *node = FindLastListNode( *pplistSource ) ;
		
		node->next = (*pplistAddition) ;
		(*pplistAddition)->prev = node ;
		
		return TRUE;
	}
}

BOOL RuptureList( SList **pplistSource , SListNode *nodeRupture , SList **pplistNew )
{
	if( nodeRupture == NULL )
		return FALSE ;
	
	if( nodeRupture->prev == NULL )
	{
		(*pplistSource) = NULL ;
		
		(*pplistNew) = nodeRupture ;
	}
	else
	{
		nodeRupture->prev->next = NULL ;
		
		nodeRupture->prev = NULL ;
		
		(*pplistNew) = nodeRupture ;
	}
	
	return TRUE;
}

BOOL DetachListNode( SList **pplistSource , SListNode *nodeDetach )
{
	if( nodeDetach == NULL )
		return FALSE ;
	
	if( nodeDetach->prev == NULL && nodeDetach->next == NULL )
	{
		(*pplistSource) = NULL ;
	}
	else if( nodeDetach->prev == NULL )
	{
		(*pplistSource) = nodeDetach->next ;
		nodeDetach->next->prev = NULL ;
		
		nodeDetach->next = NULL ;
	}
	else if( nodeDetach->next == NULL )
	{
		nodeDetach->prev->next = NULL ;
		
		nodeDetach->prev = NULL ;
	}
	else
	{
		nodeDetach->prev->next = nodeDetach->next ;
		nodeDetach->next->prev = nodeDetach->prev ;
	}
	
	return TRUE;
}

BOOL AttachListNodeAfter( SList **pplistSource , SListNode *node , SListNode *nodeAttach )
{
	if( node == nodeAttach )
		return TRUE;
	
	if( node->next == NULL )
	{
		node->next = nodeAttach ;
		nodeAttach->prev = node ;
	}
	else
	{
		nodeAttach->prev = node ;
		nodeAttach->next = node->next ;
		node->next->prev = nodeAttach ;
		node->next = nodeAttach ;
	}
	
	return TRUE;
}

BOOL AttachListNodeBefore( SList **pplistSource , SListNode *node , SListNode *nodeAttach )
{
	if( node == nodeAttach )
		return TRUE;
	
	if( node->prev == NULL )
	{
		node->prev = nodeAttach ;
		nodeAttach->next = node ;
		if( (*pplistSource) == node )
			(*pplistSource) = nodeAttach ;
	}
	else
	{
		node->prev->next = nodeAttach ;
		node->prev = nodeAttach ;
		nodeAttach->next = node ;
		nodeAttach->prev = node->prev ;
	}
	
	return TRUE;
}

/*
** ������		:	PushListStack
** ��������		:	ѹ���㵽ջʽ������
** �������˵��	:	SList *list								�����׽��
**					long max_len							ջʽ����������������
**					void *member							����Ա
**					long msize								����Ա�Ĵ�С
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

SListNode *PushStackList( SList **list , long max_len , void *member , long msize , BOOL (* FreeNodeMember)( void *pv ) )
{
	if( CountListNodes( *list ) >= max_len )
		return FALSE;
	
	return AddListNode( list , member , msize , FreeNodeMember );
}

/*
** ������		:	PopListStack
** ��������		:	��ջʽ�����е������
** �������˵��	:	SList **list			�����׽��
**					void **member			���ڴ�Ž���Ա
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL PopupStackList( SList **list , void **member )
{
	SListNode *node=NULL;
	
	if( (*list) == NULL )
		return FALSE;
	
	node=GetListIndexNode( *list , CountListNodes(*list) );
	
	if( member != NULL )
		(*member) = node->member ;
	
	if( node->prev == NULL )
	{
		free( node );
		(*list) = NULL ;
	}
	else
	{
		node->prev->next=NULL;
		free(node);
	}
	
	return TRUE;
}

/*
** ������		:	EnterListQueue
** ��������		:	�Զ���ʽ�����м�����
** �������˵��	:	SList *list								�����׽��
**					long max_len							��������������������
**					void *member							����Ա
**					long msize								����Ա�Ĵ�С
**					BOOL (* FreeNodeMember)( void *pv )		ɾ���ý���Ա�ص�����
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

SListNode *EnterQueueList( SList **list , long max_len , void *member , long msize , BOOL (* FreeNodeMember)( void *pv ) )
{
	if( CountListNodes( *list ) >= max_len && max_len != 0 )
		return FALSE;
	
	return AddListNode( list , member , msize , FreeNodeMember );
}

/*
** ������		:	LeaveQueueList
** ��������		:	�Ӷ���ʽ�������ó����
** �������˵��	:	SList **list			�����׽��
**					void **member			���ڴ�Ž���Ա
** ����ֵ		:	�ɹ������� TRUE
**					ʧ�ܣ����� FALSE
** ������־		:	2003/10/18	����
*/

BOOL LeaveQueueList( SList **list , void **member )
{
	SListNode *nodeDelete=NULL;
	
	if( (*list) == NULL )
		return FALSE;
	
	(*member) = (*list)->member ;
	
	nodeDelete = (*list) ;
	if( (*list)->next == NULL )
	{
		(*list) = NULL ;
		free( nodeDelete );
	}
	else
	{
		(*list) = (*list)->next ;
		free( nodeDelete );
		(*list)->prev = NULL ;
	}
	
	return TRUE;
}

