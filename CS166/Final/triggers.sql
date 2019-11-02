-- automatically populate part_number with incremented value 
-- 	upon insertion of the new row into part_nyc

-- CREATE SEQUENCE part_number_seq START WITH 50000;

-- return next value of the aforementioned sequence
-- 	use nextval('part_number_seq') to get next value from sequence

-- CREATE LANGUAGE plpgsql;
DROP FUNCTION IF EXISTS part_num_func() CASCADE;

CREATE OR REPLACE FUNCTION part_num_func() 
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.part_number := nextval('part_number_seq');
		-- INSERT INTO part_number VALUES (nextval('part_number_seq'));
		-- RETURN nextval(part_number_seq);
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER part_number_trigger BEFORE INSERT ON part_nyc 
	FOR EACH ROW EXECUTE PROCEDURE part_num_func();
	
-- INSERT INTO part_nyc(supplier, color, on_hand, descr) VALUES (0, 0, 20, 'Desc');

