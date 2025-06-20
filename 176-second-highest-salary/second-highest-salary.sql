SELECT
  CASE
    WHEN (SELECT COUNT(DISTINCT salary) FROM Employee) >= 2 THEN
      (SELECT DISTINCT salary 
       FROM Employee 
       ORDER BY salary DESC 
       LIMIT 1 OFFSET 1)
    ELSE NULL
  END AS SecondHighestSalary;
