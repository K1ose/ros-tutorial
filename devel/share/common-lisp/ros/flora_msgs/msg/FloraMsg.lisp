; Auto-generated. Do not edit!


(cl:in-package flora_msgs-msg)


;//! \htmlinclude FloraMsg.msg.html

(cl:defclass <FloraMsg> (roslisp-msg-protocol:ros-message)
  ((detail
    :reader detail
    :initarg :detail
    :type cl:string
    :initform "")
   (id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass FloraMsg (<FloraMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FloraMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FloraMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name flora_msgs-msg:<FloraMsg> is deprecated: use flora_msgs-msg:FloraMsg instead.")))

(cl:ensure-generic-function 'detail-val :lambda-list '(m))
(cl:defmethod detail-val ((m <FloraMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader flora_msgs-msg:detail-val is deprecated.  Use flora_msgs-msg:detail instead.")
  (detail m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <FloraMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader flora_msgs-msg:id-val is deprecated.  Use flora_msgs-msg:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FloraMsg>) ostream)
  "Serializes a message object of type '<FloraMsg>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'detail))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'detail))
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FloraMsg>) istream)
  "Deserializes a message object of type '<FloraMsg>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'detail) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'detail) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FloraMsg>)))
  "Returns string type for a message object of type '<FloraMsg>"
  "flora_msgs/FloraMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FloraMsg)))
  "Returns string type for a message object of type 'FloraMsg"
  "flora_msgs/FloraMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FloraMsg>)))
  "Returns md5sum for a message object of type '<FloraMsg>"
  "7f5528a9204f8b31c9206fc97a4a07bb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FloraMsg)))
  "Returns md5sum for a message object of type 'FloraMsg"
  "7f5528a9204f8b31c9206fc97a4a07bb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FloraMsg>)))
  "Returns full string definition for message of type '<FloraMsg>"
  (cl:format cl:nil "string detail~%int32 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FloraMsg)))
  "Returns full string definition for message of type 'FloraMsg"
  (cl:format cl:nil "string detail~%int32 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FloraMsg>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'detail))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FloraMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'FloraMsg
    (cl:cons ':detail (detail msg))
    (cl:cons ':id (id msg))
))
