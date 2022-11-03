declare
     vr_Phone_number unformatted_number%rowtype;
	 p_phone_no unformatted_number.phone_number%TYPE;
	 
 begin
 select * into  vr_Phone_number from unformatted_number where id = 3;
 p_phone_no := vr_Phone_number.phone_number;
 
 p_phone_no := '(' || substr(p_phone_no, 1, 3) ||
                ') ' || substr(p_phone_no, 4, 3) ||
                     '-' || substr(p_phone_no, 7);
     insert into formatted_number values (vr_Phone_number.id, p_phone_no);
 
     dbms_output.put_line('ID:' ||vr_Phone_number.id || 'Phone' || p_phone_no || 'inserted to formatted');
	 
 end;
 /