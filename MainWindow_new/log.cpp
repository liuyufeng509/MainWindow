#define MAX_PACKET_1_SIZE  (512)
int c_socket::sendto_data_raw(u8 *data,int len)
{
 int n;
 int i;
 u8 *p = data;
// int max_size = len;
 int head_len = 5;
 int frm_len;
 int n_pack;
 int sum=0;

 if(sta_socket != SOCKET_STA_SUC)
 {
  return my_ERR;
 }
 pthread_mutex_lock(&mutex);
 n = sendto(fd_socket, p, head_len, 0,(struct sockaddr *)&my_client_addr,sizeof(my_client_addr));

 if(n == head_len)
 {
  frm_len = len - head_len;
  n_pack = frm_len/MAX_PACKET_1_SIZE + (frm_len%MAX_PACKET_1_SIZE == 0)?(0):(1);
  printf("%s recv 1 frm_len=%d, n_pack=%d \n",descrip,frm_len,n_pack);

  p +=n;
  for(i=0;i<n_pack;i++)
  {
   n = sendto(fd_socket, p, MAX_PACKET_1_SIZE, 0,(struct sockaddr *)&my_client_addr,sizeof(my_client_addr));
//   printf("%s recv 2  i=%d,n= %d\n",descrip,i,n);
   if (n > 0)
   {
//    printf("%s recv 3  n=%d,\n",descrip,n);
   }
   p +=n;
  }
 }


 pthread_mutex_unlock(&mutex);
 if (n < 0)
 {
  my_debug("%s sendto_data_raw(),faile! err=%d, len=%d \n",descrip,n,len);

  return my_TIME_OUT_ERR;
 }else
 {
//  my_debug("%s sendto_raw [实际发送=%d,想要发送=%d]  =[  ",descrip,n,len);
//
//  for(i=0;i<n;i++)
//  {
//   printf("%02x ",data[i]);
//  }
//
//  printf("]\n");


  return my_SUC;
 }
}
付文涛 09:59:24
int c_socket::recvfrom_data_raw(u8 *str,int len)
{
 int n;
 int i;
 u8 *p=str;
 int max_size = len;
 int head_len = 5;
 int frm_len;
 int n_pack;
 int sum=0;


 socklen_t sock_size;

 if(sta_socket != SOCKET_STA_SUC)
 {
  return my_ERR;
 }
 pthread_mutex_lock(&mutex);
// printf("%s recv 00000000000 len=%d  =[  ",descrip,len);
// n=recv(fd_socket, p, head_len, 0);
 n = recvfrom(fd_socket, p, head_len, 0,(struct sockaddr *)&my_client_addr,&sock_size);
// printf("%s recv 0  n=%d  \n",descrip,n);
 sum = n;
 if (n >0)
 {
  printf("%s recv 0  n=%d,p[0]=[ %c ] \n",descrip,n,p[0]);
 }


 if(n== head_len)
 {

  if(p[0] == '<')
  {
   memcpy(&frm_len,(p+1),4);

   frm_len +=(2+1);//校验和与结束符;

   n_pack = frm_len/MAX_PACKET_1_SIZE + (frm_len%MAX_PACKET_1_SIZE == 0)?(0):(1);
   printf("%s recv 1 frm_len=%d, n_pack=%d \n",descrip,frm_len,n_pack);

   p +=n;
   sum +=n;
   for(i=0;i<n_pack;i++)
   {
    n = recvfrom(fd_socket, p, MAX_PACKET_1_SIZE, 0,(struct sockaddr *)&my_client_addr,&sock_size);

    printf("%s recv 2  i=%d,n= %d\n",descrip,i,n);
    if (n > 0)
    {
     printf("%s recv 3  n=%d,\n",descrip,n);
    }
    p +=n;
    sum +=n;
   }


  }
 }


 pthread_mutex_unlock(&mutex);
 if (sum < 0)
 {
//  my_debug("recv socket data_string faile! n=0x%x\n",n);
  return my_TIME_OUT_ERR;
 }else
 {
  my_debug("%s recv [size=%d,max=%d]  =[  ",descrip,sum,len);

  for(i=0;i<sum;i++)
  {
//   printf("%02x ",str[i]);
  }

  printf("]\n");


  return sum;
 }
}