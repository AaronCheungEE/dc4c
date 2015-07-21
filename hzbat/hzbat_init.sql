set names gb2312 ;

-- ----------------------------------------------------------------------------
-- ������������
-- ----------------------------------------------------------------------------

truncate table pm_hzbat_schedule ;
truncate table pm_hzbat_batches_info ;
truncate table pm_hzbat_batches_filter ;
truncate table pm_hzbat_batches_tasks ;
truncate table pm_hzbat_batches_direction ;

-- ----------------------------------------------------------------------------
-- ����ƻ�������
-- ----------------------------------------------------------------------------

INSERT INTO pm_hzbat_schedule VALUES (10,'POIT_STAD','���ݱ�׼��','','',0);
INSERT INTO pm_hzbat_schedule VALUES (20,'POIT_CALC','���ּ���','','',0);
INSERT INTO pm_hzbat_schedule VALUES (25,'POIT_DAYE','����','','',0);
INSERT INTO pm_hzbat_schedule VALUES (30,'POIT_RPT','����','','',0);

-- ----------------------------------------------------------------------------
-- ����������Ϣ������
-- ----------------------------------------------------------------------------

-- ���ݱ�׼���ƻ�

INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHA901','�ͻ���Ϣͬ��',0,0,1,'','',0,'POTHA901 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB001','����ൽ��׼����',0,0,1,'','',0,'POTHB001 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB002','�Ŵ��ൽ��׼����',0,0,1,'','',0,'POTHB002 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB003','�������ݵ���׼����',0,0,1,'','',0,'POTHB003 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB004','�ƽ�T+D���ݵ���׼����',0,0,1,'','',0,'POTHB004 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB005','���ӹ�ծ����׼����',0,0,1,'','',0,'POTHB005 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB006','�������ݵ���׼����',0,0,1,'','',0,'POTHB006 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB007','��ǿ����ݵ���׼����',0,0,1,'','',0,'POTHB007 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB008','���������ݵ���׼����',0,0,1,'','',0,'POTHB008 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB009','΢���������ݵ���׼����',0,0,1,'','',0,'POTHB009 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB010','��ǿ�pos�������ݵ���׼����',0,0,1,'','',0,'POTHB010 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB011','ƾ֤ʽ��ծ����׼����',0,0,1,'','',0,'POTHB011 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB012','����ʽ��ծ����׼����',0,0,1,'','',0,'POTHB012 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB013','���ǩԼ����׼����',0,0,1,'','',0,'POTHB013 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB014','�Ŵ��ൽ��׼����',0,0,1,'','',0,'POTHB014 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB015','��ƺͻ��𵽱�׼����',0,0,1,'','',0,'POTHB015 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB016','���ÿ�pos���ѵ���׼����',0,0,1,'','',0,'POTHB016 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB017','�����ൽ��׼����',0,0,1,'','',0,'POTHB017 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB018','��������ǩԼ���ݱ�׼��',0,0,1,'','',0,'POTHB018 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB019','�ṹ�Դ��',0,0,1,'','',0,'POTHB019 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB020','�����Զ�ת��',0,0,1,'','',0,'POTHB020 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB021','�ʽ�鼯ǩԼ',0,0,1,'','',0,'POTHB021 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB022','΢��������ǩԼ',0,0,1,'','',0,'POTHB022 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB023','����ҵ��ǩԼ',0,0,1,'','',0,'POTHB023 -s',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB024','����POS���߽�����',0,0,1,'','',0,'POTHB024 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB025','���𰴹������ͻ��ֵ���׼',0,0,1,'','',0,'POTHB025 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB026','���߽ɷѰ������ͻ���',0,0,1,'','',0,'POTHB026 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB027','���ÿ�����',0,0,1,'','',0,'POTHB027 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB028','�Կ�����',0,0,1,'','',0,'POTHB028 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB029','ѧ�ѽɷѰ������ͻ���',0,0,1,'','',0,'POTHB029 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB030','��ƹ��򰴽���ͻ���',0,0,1,'','',0,'POTHB030 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_STAD','POTHB031','�ʽ�鼯�ɹ��ͻ���',0,0,1,'','',0,'POTHB031 -s',60,'',0,0,0,0);

-- ���ּ���ƻ�

INSERT INTO pm_hzbat_batches_info VALUES ('POIT_CALC','POTHC001','���ּ���',0,0,1,'','',0,'POTHC001 -m',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_CALC','POTHC101','���ֻ���',0,0,1,'','',0,'POTHC101 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_CALC','POTHC201','���ֻ���',0,0,1,'','',0,'POTHC201 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_CALC','POTHC301','��������',0,0,1,'','',0,'POTHC301 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_CALC','POTHC302','ʱ���������',0,0,1,'','',0,'POTHC302 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_CALC','POTHC401','����ʧЧ',0,0,1,'','',0,'POTHC401 -s',60,'',0,0,0,0);

-- ���ּ���ƻ�

INSERT INTO pm_hzbat_batches_info VALUES ('POIT_DAYE','POTHD001','ҵ�������л�',0,0,1,'','',0,'POTHD001 -s',60,'',0,0,0,0);

-- �������ɼƻ�

INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR001','�����˺��»���',0,0,1,'','',0,'POTHR001 -m',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR002','��Ŀ��ϸÿ�ջ���',0,0,1,'','',0,'POTHR002 -m',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR003','�ͻ���Ŀ��ϸÿ��TOP',0,0,1,'','',0,'POTHR003 -m',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR101','�ͻ����ֲ����ձ���',0,0,1,'','',0,'POTHR101 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR201','�ͻ����ֲ����±���',0,0,1,'','',0,'POTHR201 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR301','�ͻ����ֲ���������',0,0,1,'','',0,'POTHR301 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR401','�ͻ����ֲ����걨��',0,0,1,'','',0,'POTHR401 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR102','���߻��ֲ����ձ���',0,0,1,'','',0,'POTHR102 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR202','���߻��ֲ����±���',0,0,1,'','',0,'POTHR202 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR302','���߻��ֲ���������',0,0,1,'','',0,'POTHR302 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR402','���߻��ֲ����걨��',0,0,1,'','',0,'POTHR402 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR103','���߿ͻ����ֲ����ձ���',0,0,1,'','',0,'POTHR103 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR203','���߿ͻ����ֲ����±���',0,0,1,'','',0,'POTHR203 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR303','���߿ͻ����ֲ���������',0,0,1,'','',0,'POTHR303 -s',60,'',0,0,0,0);
INSERT INTO pm_hzbat_batches_info VALUES ('POIT_RPT','POTHR403','���߿ͻ����ֲ����걨��',0,0,1,'','',0,'POTHR403 -s',60,'',0,0,0,0);

-- ----------------------------------------------------------------------------
-- �����������˱�����
-- ----------------------------------------------------------------------------

INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_CALC','POTHC302','DD','ME');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR201','DD','ME');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR202','DD','ME');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR203','DD','ME');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR301','MM-DD','03-31,06-30,09-30,12-31');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR302','MM-DD','03-31,06-30,09-30,12-31');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR303','MM-DD','03-31,06-30,09-30,12-31');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR401','MM-DD','12-31');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR402','MM-DD','12-31');
INSERT INTO pm_hzbat_batches_filter VALUES ('POIT_RPT','POTHR403','MM-DD','12-31');

-- ----------------------------------------------------------------------------
-- ������������������
-- ----------------------------------------------------------------------------

-- ���ݱ�׼���ƻ�

INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHA901');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB001');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB002');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB003');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB004');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB005');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB006');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB007');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB008');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB009');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB010');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB011');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB012');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB013');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB014');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB015');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB016');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB017');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB018');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB019');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB020');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB021');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB022');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB023');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB024');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB025');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB026');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB027');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB028');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB029');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB030');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','','POTHB031');

INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHA901','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB001','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB002','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB003','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB004','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB005','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB006','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB007','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB008','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB009','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB010','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB011','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB012','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB013','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB014','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB015','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB016','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB017','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB018','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB019','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB020','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB021','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB022','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB023','');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB024','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB025','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB026','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB027','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB028','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB029','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB030','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_STAD','POTHB031','');

-- ���ּ���ƻ�

INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','','POTHC001');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','POTHC001','POTHC101');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','POTHC101','POTHC201');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','POTHC201','POTHC301');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','POTHC301','POTHC302');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','POTHC302','POTHC401');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_CALC','POTHC401','');

-- ���ּ���ƻ�

INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_DAYE','','POTHD001');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_DAYE','POTHD001','');

-- �������ɼƻ�

INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','','POTHR001');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR001','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','','POTHR002');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR002','POTHR003');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR003','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','','POTHR101');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR101','POTHR201');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR201','POTHR301');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR301','POTHR401');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR401','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','','POTHR102');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR102','POTHR202');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR202','POTHR302');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR302','POTHR402');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR402','');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','','POTHR103');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR103','POTHR203');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR203','POTHR303');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR303','POTHR403');
INSERT INTO pm_hzbat_batches_direction VALUES ('POIT_RPT','POTHR403','');

-- ----------------------------------------------------------------------------
-- �������������
-- ----------------------------------------------------------------------------

-- ----------------------------------------------------------------------------
-- ������С�ƻ�
-- ----------------------------------------------------------------------------

-- INSERT INTO pm_hzbat_schedule VALUES (-5,'TEST','����','','',0);

-- INSERT INTO pm_hzbat_batches_info VALUES ('TEST','TEST1','����1',0,0,1,'','',0,'dc4c_test_worker_sleep 1',60,'',0,0,0,0);
-- INSERT INTO pm_hzbat_batches_info VALUES ('TEST','TEST2','����2',0,0,1,'','',0,'dc4c_test_worker_sleep 2',60,'',0,0,0,0);

-- INSERT INTO pm_hzbat_batches_direction VALUES ('TEST','','TEST1');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('TEST','TEST1','TEST2');
-- INSERT INTO pm_hzbat_batches_direction VALUES ('TEST','TEST2','');

