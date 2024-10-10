# USB Transfers


## Pipes and End points

Data is send specific `endpoint` only from USB Software

![alt text](./images/pipes_endpoints.png)


* Each device/host has multiple endpoints
    * `Endpoint` is virtual communication channel between device and host.
    * Each endpoints can have different type of USB transaction
        * SETUP
        * BULK
        * Interrupt
        * ISOchronous
    * `Endpoint 0` is reserved for enumeration & configuration of the USB device.
    * Max 16 Endpoints (bi-directional), depends on HS.

* `USB Pipe` is connection from host to specific endpoint on specific device.
    * It constists of endpoint number and device address.
    * It is used from host perspective.

## Packets and Structure


![](./images/packet_1.png)

![](./images/packet_1_data.png)

![](./images/Packet_1_token.png)

![](./images/packet_handshake.png)

## Address

![](./images/address.png)

**Address Assign**

Host send query for state changed when new device is connected. Hub responds. 

It assign it to address 0, then find free address and assign to the new.

## Start of Frame

![](./images/start_of_frame.png)


## Transaction

![](./images/transaction.png)

![](./images/transaction_handshake.png)

![](./images/bulk_transaction_IN.png)

![](./images/bulk_in.png)

`transaction 2` when ACK is not received so, data is transmitted again till the correct data is received.

![](./images/bulk_out.png)

![](./images/bulk_out_1.png)

![](./images/data_ack_error_handle.png)

![](./images/isochronous_transaction.png)

![](./images/iso_in_out.png)

![](./images/interrupt_transaction.png)

![](./images/interrupt_transaction_1.png)

![](./images/interrupt_IN.png)

![](./images/interrupt_out.png)


## Control Setup Transaction

![](./images/control_setup_transaction.png)

![](./images/setup.png)

![](./images/control_read_write.png)

![](./images/control_sequence_write.png)

![](./images/control_sequence_read.png)

![](./images/control_seq_no_data.png)

![](./images/Naming_conventions_USB.png)

![](./images/request_header.png)

![](./images/requests.png)

![](./images/usb_request_example.png)

![](./images/usb_req_eg_stall.png)

![](./images/split_ping.png)

![](./images/bandwidt_constraint.png)

