/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * Author:  ntrog
 * Created: Jun 6, 2019
 */

create table ItemsInPad

(

person_name varchar(30),

item_name varchar(30),

date_checked_out varchar(30),

checked_back_in varchar(30)


);

insert into ItemsInPad
(person_name, item_name, date_checked_out, checked_back_in)
values('Nathan Rogers', 'iMac', '9/30/2018', 'Yes');

insert into ItemsInPad
(person_name, item_name, date_checked_out, checked_back_in)
values('Dalton Stone', 'GoPro', '9/30/2018', 'Yes');

insert into ItemsInPad
(person_name, item_name, date_checked_out, checked_back_in)
values('Nathan Rogers', 'GoPro', '9/30/2018', 'Yes');

insert into ItemsInPad
(person_name, item_name, date_checked_out, checked_back_in)
values('Dalton Stone', 'Alienware', '9/30/2018', 'Yes');

/*drop table ItemsInPad;*/
