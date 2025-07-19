SELECT ROUND(
  COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity),
  2
) AS fraction
FROM Activity
where (player_id,event_date) in
(
    select player_id, date_add(min(event_date),interval 1 day)
    from Activity
    group by player_id
)
