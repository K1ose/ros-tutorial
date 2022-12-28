
(cl:in-package :asdf)

(defsystem "flora_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "FloraMsg" :depends-on ("_package_FloraMsg"))
    (:file "_package_FloraMsg" :depends-on ("_package"))
    (:file "FloraMsg" :depends-on ("_package_FloraMsg"))
    (:file "_package_FloraMsg" :depends-on ("_package"))
  ))