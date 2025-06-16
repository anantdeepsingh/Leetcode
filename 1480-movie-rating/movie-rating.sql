-- Get top user by number of ratings
SELECT name AS results
FROM (
  SELECT name
  FROM Users u
  JOIN MovieRating m ON u.user_id = m.user_id
  GROUP BY name
  ORDER BY COUNT(*) DESC, name ASC
  LIMIT 1
) AS top_user

UNION ALL

-- Get top-rated movie in Feb 2020
SELECT title AS results
FROM (
  SELECT title
  FROM Movies t
  JOIN MovieRating m ON t.movie_id = m.movie_id
  WHERE MONTH(created_at) = 2 AND YEAR(created_at) = 2020
  GROUP BY title
  ORDER BY AVG(rating) DESC, title ASC
  LIMIT 1
) AS top_movie;
