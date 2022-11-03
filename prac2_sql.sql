variable b_name varchar2(25)
variable b_sal number
execute quey_emp(171, :b_name, :b_sal)
print b_name b_sal