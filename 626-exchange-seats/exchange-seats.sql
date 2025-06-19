SELECT 
  s1.id,
  CASE
    WHEN s1.id % 2 = 1 AND s1.id + 1 <= (SELECT MAX(id) FROM Seat) THEN
      (SELECT student FROM Seat s2 WHERE s2.id = s1.id + 1)
    WHEN s1.id % 2 = 0 THEN
      (SELECT student FROM Seat s2 WHERE s2.id = s1.id - 1)
    ELSE s1.student
  END AS student
FROM Seat s1
ORDER BY s1.id;
