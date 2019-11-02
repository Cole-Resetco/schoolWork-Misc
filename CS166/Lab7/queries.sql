--1. Count how many parts in NYC have more than 70 parts on hand
--2. Count how many total parts on hand, in both NYC and SFO, are Red
--3. List all the suppliers that have more total on hand parts in NYC than
--they do in SFO.
--4. List all suppliers that supply parts in NYC that aren’t supplied by
--anyone in SFO.
--5. Update all of the NYC on hand values to on hand - 10.
--6. Delete all parts from NYC which have less than 30 parts on hand.

--1
SELECT on_hand, count(*) FROM part_nyc WHERE on_hand > 70 GROUP BY on_hand;


--2
SELECT sum(on_hand) FROM (SELECT on_hand FROM part_nyc N, color C WHERE N.color = C.color_id AND C.color_name = 'Red' UNION ALL SELECT on_hand FROM part_sfo S, color C2 WHERE S.color = C2.color_id AND  C2.color_name = 'Red') as temp;


--3
--SELECT supplier_name, COUNT(*) FROM supplier S1, part_nyc N, part_sfo S WHERE S1.supplier_id = N.supplier AND S1.supplier_id = S.supplier AND N.on_hand > S.on_hand GROUP BY supplier_name;


--4

--5
UPDATE part_nyc
SET on_hand = on_hand - 10;


--6
DELETE FROM part_nyc
WHERE on_hand < 30;

