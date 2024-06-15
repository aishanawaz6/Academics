#Creating simulator object 
set ns [new Simulator]   

#Creating the nam file
set nf [open out.nam w]    
  
#It opens the file 'out.nam' for writing and gives it the file handle 'nf'. 
$ns namtrace-all $nf

#Finish Procedure  (closes the trace file and starts nam)
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
        }
        
#1. Write a Tcl script that forms a network consisting of 7 nodes, numbered #from 0 to 6, forming a ring topology. 

#Defining Nodes
for {set j 0} {$j<7} {incr j} {
set arr($j) [$ns node]
}


#2. The links have a 512Kbps bandwidth with 5ms delay and droptail queue.
for {set j 0} {$j<7} {incr j} {
$ns duplex-link $arr($j) $arr([expr ($j+1)%7]) 512Kb 5ms DropTail    
}
$ns duplex-link-op $arr(0) $arr(1) orient right-down
$ns duplex-link-op $arr(1) $arr(2) orient right-down
$ns duplex-link-op $arr(2) $arr(3) orient left-down
$ns duplex-link-op $arr(3) $arr(4) orient left-up
$ns duplex-link-op $arr(4) $arr(5) orient left-up 
$ns duplex-link-op $arr(5) $arr(6) orient right-up 
$ns duplex-link-op $arr(6) $arr(0) orient right-up



#3. Set the routing protocol to DV (Distance vector).
$ns rtproto DV

#4. Send UDP packets from node 0 to node 3 with the rate of 100 packets/sec with each packet having a size of 1 Kilo Bytes.

#Specifying the UDP agent
set udp0 [new Agent/UDP]
#Specifying udp traffic to have red color as defined in the second line of program
$udp0 set fid_ 1

#Attaching the UDP agent with node 0
$ns attach-agent $arr(0) $udp0
#Specifying the Null agent
set null0 [new Agent/Null]

#Attaching the NULL agent with node3
$ns attach-agent $arr(3) $null0

#Connecting both udp0 and null0 agents for transferring data between node 0 and node 3
$ns connect $udp0 $null0
 
#Specifying the CBR agent to generate the traffic over udp0 agent
set cbr0 [new Application/Traffic/CBR]

#Each packet having 1000 bytes
$cbr0 set packetSize_ 1000

#EAch packet will be generated after 1ms i.e., 100 packets per second
$cbr0 set interval 0.001

#Attaching cbr0 with udp0
$cbr0 attach-agent $udp0


#5. Start transmission at 0.02.Page 3 of 4 November 26 th , 2022
#Starting the cbr0 at 0.02 simulaio time
$ns at 0.02 "$cbr0 start"


#6. Bring down the link between node 2 and node 3 at 0.4.
$ns rtmodel-at 0.40 down $arr(2) $arr(3)

#7. Bring the dropped link back up at 1.0.
$ns rtmodel-at 1.0 up $arr(2) $arr(3)

#8. Finish the transmission at 1.5 End the simulation at 2.0.

#Stoping the cbr0 at 1.5 simulation time
$ns at 1.5 "$cbr0 stop"
$ns at 2.0 "finish"

$ns run

