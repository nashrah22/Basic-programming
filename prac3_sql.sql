declare
v_num number:=& sv_num;
begin
if v_num<0
then
dbms_output.put_line(v_num||' is a negative number');
elsif v-num=0
then 
dbms_output.put_line(v_num||' is equal to zero');
else
dbms_output.put_line(v_num||' is a positive number');
end if;
end;
/

