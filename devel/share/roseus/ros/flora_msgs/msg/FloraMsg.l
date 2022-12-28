;; Auto-generated. Do not edit!


(when (boundp 'flora_msgs::FloraMsg)
  (if (not (find-package "FLORA_MSGS"))
    (make-package "FLORA_MSGS"))
  (shadow 'FloraMsg (find-package "FLORA_MSGS")))
(unless (find-package "FLORA_MSGS::FLORAMSG")
  (make-package "FLORA_MSGS::FLORAMSG"))

(in-package "ROS")
;;//! \htmlinclude FloraMsg.msg.html


(defclass flora_msgs::FloraMsg
  :super ros::object
  :slots (_detail _id ))

(defmethod flora_msgs::FloraMsg
  (:init
   (&key
    ((:detail __detail) "")
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _detail (string __detail))
   (setq _id (round __id))
   self)
  (:detail
   (&optional __detail)
   (if __detail (setq _detail __detail)) _detail)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; string _detail
    4 (length _detail)
    ;; int32 _id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _detail
       (write-long (length _detail) s) (princ _detail s)
     ;; int32 _id
       (write-long _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _detail
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _detail (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get flora_msgs::FloraMsg :md5sum-) "7f5528a9204f8b31c9206fc97a4a07bb")
(setf (get flora_msgs::FloraMsg :datatype-) "flora_msgs/FloraMsg")
(setf (get flora_msgs::FloraMsg :definition-)
      "string detail
int32 id

")



(provide :flora_msgs/FloraMsg "7f5528a9204f8b31c9206fc97a4a07bb")


