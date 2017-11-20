/* change light state by altering  l_slave_array[0][i]  values */
#define F_slave1 0
#define F_slave2 1


void force_control()
{
if(slave_reads[F_slave1][0]>150)
l_slave_array[0][2]=1;

if(slave_reads[F_slave1][0]<100)
l_slave_array[F_slave1][2]=0;

/*for(int i=0;i<5;i++)
{
  Serial.print(l_slave_array[0][i]);
  Serial.print(" ");
  Serial.println("");
}*/

}

