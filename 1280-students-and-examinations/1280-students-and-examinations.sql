SELECT 
    stu.student_id student_id,
    stu.student_name student_name,
    sub.subject_name subject_name,
    COUNT(e.student_id) attended_exams
FROM Students stu
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
ON 
    stu.student_id = e.student_id
    AND sub.subject_name = e.subject_name
GROUP BY stu.student_id, stu.student_id, sub.subject_name
ORDER BY stu.student_id, sub.subject_name;