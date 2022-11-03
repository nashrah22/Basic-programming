declare
cursor c_zip is
select * from employees;
vr_zip c_zip%rowtype;
v_salary vr_zip.salary%type; 
v_tax vr_zip.salary%type;


begin
open c_zip;
fetch c_zip into vr_zip;
while c_zip%found
loop
v_salary :=((vr_zip.salary*12)+(vr_zip.salary*12*nvl(vr_zip.commission_pct, 0)));
v_tax:= v_salary*0.1;
insert into employee_tax values (vr_zip.employee_id, vr_zip.last_name, vr_zip.salary, v_tax );
commit;

fetch c_zip into vr_zip;
end loop;


end;
/