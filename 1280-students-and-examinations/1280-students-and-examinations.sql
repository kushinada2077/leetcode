SELECT stu.student_id, stu.student_name, sub.subject_name, (SELECT COUNT(*) FROM Examinations AS e
WHERE stu.student_id = e.student_id AND sub.subject_name = e.subject_name) AS attended_exams
FROM Students AS stu, Subjects AS sub
ORDER BY stu.student_id, sub.subject_name;