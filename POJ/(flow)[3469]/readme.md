[��ʶ��]

���˼򵥵����ڿ������Ĵ����ģ�ͣ����ǻ�Ҫ����һЩ�����ŵ�ģ�ͣ�����˵����⡣

��Ŀ�̣ܶ���Ȼ���ⲻ����ʲô�ϰ���

Ȼ���������ܽ�һ����Ŀ��Ҫ��

* ����һ������ֻ����һ̨����������

* �����������(a,b)����ͬһ̨���������Ļ���Ҫ֧������ķ��á�

է������Ŀ�����ú���˼����

�������һ���еڶ������Ƶ�����(i,j)��˵��������һ̨���������Ļ�������

min(cl[i]+cl[j],cr[i]+cr[j])

����clΪcost_l��crΪcost_r

Ȼ�����������һ�����������Ļ�������

min(cl[i]+cr[j],cr[i]+cl[j])+c_extra��

����Ҫ�������������ȡ��Сֵ��

�ٻ�һ������ı���


	i   cost_l			cost_r

	        	   extra

	j   cost_l			cost_r


����������˼·����ѡ���ƺ���Ȼ��֪����ô����

Ȼ�����ƺ�Ҫ��һ�ֶ����ܹ��������ӵطֱ棬��Ϊ�ƺ�״̬�ľ����Ǻܸ��ӵġ�

��ô�����extra=0ʱ����cl[i]+cl[j]��cr[i]+cr[j]�Ƚ���ѡС�ġ�

���cost_l��������޷����ܣ���cl[i]+cl[j]+extra��cr[i]+cl[j]������Ҫѡһ���Ƚ�С�ġ�

��Ӧ����һ��ˮ�����ɵĹ��̡���ͻȻ���뵽�����������ص㣬һ������·�ϵ���������Ӧ�����ܹ�����С��ô��

�ðɡ���������һ��ͼ��

       
	         -----[1]-----   i   -----[2]-----

	     / 	  (cl_i)    		    ��cr_i��     \

	S -                		                          - T

	      \     ��cl_j��		    ��cr_j��     /

		   -----[3]-----   j   -----[4]-----


�ðɣ��������û��extra��Ӧ�����������ˣ������������ͼֻҪ����������ɡ�

��ô����һ��extra�����ƣ���ô�ģ�

**�����������ͬһ�������ϣ���Ҫ�ж���ķ���**

���ǿ���������Ǽ���ѡ����[1][4]�Ļ�������Ҫ����[3]������Ҫ��[4]��[2]������Ҫ��[1]��[1]���㲻��[2]��[4]����������[3]��˵̫���ˇ塢����Ȼ�Ļ���ѡ������С�ġ���

��ô��ô���أ�

��[3]�Ķ���ĸ�Ū��[2]ȥ��

�����(i,j)������Ϊextra�Ļ�����������ۡ�

���w([3]-[4])>=w([2]-[1])����ô�Ҿͻ��[3]����Ū��[2]��ȥ��

w([2]-[1])<extra����ô��Ȼ�������[2]+[4]��

w([2]-[1])>=extra����ô�������[1]+[4]+extra.

���w([3]-[4])<extra����ô

w([2]-[1])<w([3]-[4])���������[2]+[4]

w([3]-[4])<=w([2]-[1])<extra���������[3]+[1]

w([2]-[1])>extra���������[1]+extra+[4]��

��ϸ����һ�£��ƺ����е������Ҫ���ǵ��ˡ�

Ȼ�󣬽�ͼ�����練��:

S,T,A(1~N)

(1) ���ڵ�i��A����(S,i,cost_1)��(i,T,cost_2)

(2) ���ڵڶ������������mair(a,b,w)����(a,b,w),(b,a,w)

Ȼ�󣬾�����ʶ���Ľ�����

�������������������������������������������������������������������yy��

��ʵ�������ٴ���С��ĽǶȷ�����

����A��B���������û��ϵ���ͻ�ֱ�ȡС�ģ���������һ�¾���2���

Ȼ���������ٴ�˼������������й�ϵ����ô�����������Ҫ�ֿ������Ļ�����С����һ��Ҫ��������Ϊextra�������

���Ǽ������ǣ��������ȡ��A��way1��B��way2���;ͱ���Ҫȡ��A��B����������s��Ȼ���Դ�s�ߵ�t�������ȡ(A,B)�Ļ����Ǿͱ���Ҫȡ��way1��way1�������ߣ�way2��way2�����������ܲ���ͨ��

���ƺ��Ǵ���ͨ�Է����ġ�

